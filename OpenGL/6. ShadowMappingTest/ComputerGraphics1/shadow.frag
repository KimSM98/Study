#version 410 core

in vec4 pos;

out vec4 out_Color;



void main(void)
{
	
	 out_Color = vec4(vec3(pos.z/pos.w), 1);

}
