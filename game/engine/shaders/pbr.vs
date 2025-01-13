#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in int aVertex_Group;
layout (location = 2) in vec3 aNormal;
layout (location = 3) in vec2 aUV;

out vec2 UV;

uniform vec3 a;

void main()
{
	gl_Position = vec4(a, 1.0) + vec4(aPos, 1.0);
	UV = vec2(aUV.x, aUV.y);
}