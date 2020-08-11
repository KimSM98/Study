#version 150 core
uniform vec3 lightPos = vec3(5,5,5);
uniform vec3 lightColor = vec3(1,1,1);
uniform vec3 diffColor = vec3(1,0.4,0);
uniform vec3 specColor = vec3(1);
uniform vec3 ambientLight = vec3(0.5);
uniform mat4 viewMat = mat4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,-3,1);

 
in vec3 normal;
in vec4 worldPos;

out vec4 out_Color;

void main(void)
{
	 
	 vec3 N = normalize(normal);
	 vec3 L = normalize(lightPos - worldPos.xyz);

	 vec3 R = 2 * dot(L, N) * N - L;
	 vec3 V = normalize(-(viewMat * worldPos).xyz);

	 float diffFactor = clamp(dot(N,L), 0, 1);
	 //specFactor = pow(clamp(dot(R, V), 0, 1), 100);

	 vec3 H = normalize(L + V);
	 float specFactor = pow(clamp(dot(H,N), 0, 1), 1000);

	 vec3 color = lightColor * diffColor * diffFactor;
	 color += ambientLight * diffColor;
	 color += lightColor * specColor * diffFactor * specFactor;

	
	out_Color = vec4(color, 1.0);
}
