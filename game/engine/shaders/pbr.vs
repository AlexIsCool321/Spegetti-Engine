#version 330 core

layout (location = 0) in vec3 aPosition;
layout (location = 1) in int aVertex_Group;
layout (location = 2) in vec3 aNormal;
layout (location = 3) in vec2 aUV;


out vec2 UV;
out vec3 Normal;
out vec3 Frag_Position;


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position		= projection * view * model * vec4(aPosition, 1.0);
	Frag_Position	= vec3(model * vec4(aPosition, 1.0));
	UV				= aUV;
	Normal			= aNormal;
}