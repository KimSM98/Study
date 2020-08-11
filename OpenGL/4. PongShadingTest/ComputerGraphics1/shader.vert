#version 410 core

layout(location=0) in vec3 in_Position;
layout(location=1) in vec3 in_Normal;

uniform mat4 viewMat = mat4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,-3,1);
uniform mat4 projMat = mat4(1.299038, 0, 0, 0, 0, 1.732051, 0, 0, 0, 0, -1.002002, -1.0, 0, 0, -0.2002, 0);
uniform mat4 objectMat;

out vec4 worldPos;
out vec3 normal;

void main(void) {
	worldPos = objectMat*vec4(in_Position, 1.0);
	normal = normalize(objectMat*vec4(in_Normal, 0)).xyz; 
	gl_Position= projMat*viewMat* worldPos;
}

