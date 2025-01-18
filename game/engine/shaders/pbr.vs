#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in int aVertex_Group;
layout (location = 2) in vec3 aNormal;
layout (location = 3) in vec2 aUV;

out vec2 UV;

uniform mat4 transform;

void main()
{
	gl_Position = transform * vec4(aPos, 1.0);
	UV = vec2(aUV.x, aUV.y);
}