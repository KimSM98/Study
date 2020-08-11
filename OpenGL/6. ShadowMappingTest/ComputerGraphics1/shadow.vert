#version 410 core

layout(location=0) in vec3 in_Position;

uniform mat4 shadowMat;
out vec4 pos;

void main(void) {
	gl_Position = shadowMat*vec4(in_Position,1); 
	pos = gl_Position;

}

