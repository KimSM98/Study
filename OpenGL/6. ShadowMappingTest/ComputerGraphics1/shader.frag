#version 150 core
uniform vec3 lightPos = vec3(5,5,5);
uniform vec3 lightColor = vec3(1,1,1);
//uniform vec3 diffColor = vec3(1,0.4,0);
uniform vec3 specColor = vec3(1);
uniform vec3 ambientLight = vec3(0.5);
uniform mat4 viewMat = mat4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,-3,1);

uniform sampler2D diffTex;
uniform sampler2D bumpTex;
uniform sampler2D shadowMap;

in vec3 normal;
in vec4 worldPos; 
in vec2 texCoord;
in vec4 shadowPos;

out vec4 out_Color;

mat3 getTBN( vec3 N ) {
    vec3 Q1 = dFdx(worldPos.xyz), Q2 = dFdy(worldPos.xyz);
    vec2 st1 = dFdx(texCoord), st2 = dFdy(texCoord);
    float D = st1.s*st2.t-st2.s*st1.t;
    return mat3(normalize(( Q1*st2.t - Q2*st1.t )*D),
                       normalize((-Q1*st2.s + Q2*st1.s )*D), N);
}

vec2 poissonDisk[4] = vec2[](
	vec2( -0.94201624, -0.39906216 ),
	vec2( 0.94558609, -0.76890725 ),
	vec2( -0.094184101, -0.92938870 ),
	vec2( 0.34495938, 0.29387760 ) ); 



void main(void)
{
	 vec3 diffColor = texture( diffTex, texCoord).rgb;

	 vec3 N = normalize(normal);

	 mat3 TBN = getTBN(N);
	 float Bu = texture( bumpTex, texCoord + vec2(0.0001, 0)).r
	 - texture( bumpTex, texCoord - vec2(0.0001, 0)).r;
	 

	 float Bv = texture( bumpTex, texCoord + vec2(0, 0.0001)).r
	 - texture( bumpTex, texCoord - vec2(0, 0.0001)).r
	 ;
	 vec3 bumpVec = vec3(-Bu*15., -Bv*15., 1 );
	 N = normalize( TBN* bumpVec );


	 vec3 L = normalize(lightPos - worldPos.xyz);

	 vec3 R = 2 * dot(L, N) * N - L;
	 vec3 V = normalize(-(viewMat * worldPos).xyz);

	 float diffFactor = clamp(dot(N,L), 0, 1);
	 //specFactor = pow(clamp(dot(R, V), 0, 1), 100);

	 vec3 H = normalize(L + V);
	 float specFactor = pow(clamp(dot(H,N), 0, 1), 1000);

	 vec3 color = lightColor * diffColor * diffFactor;
	// color += ambientLight * diffColor;
	 color += lightColor * specColor * diffFactor * specFactor;
	 
	 float z = shadowPos.z/shadowPos.w;
	 vec2 shadowCoord = (shadowPos.xy/shadowPos.w+vec2(1))/2;

	 float bias = 0.005 * tan(acos(dot(N,L)));
	 float visibility = 1.0;
	 for(int i=0; i<4; i++){
		float shadowZ = texture(shadowMap, shadowCoord + poissonDisk[i]*0.001).r;
		if ( shadowZ < z-bias)
			visibility -= 0.2;
	 }
	 out_Color = vec4(pow(color*visibility, vec3(1/2.2)), 1.0);

}
