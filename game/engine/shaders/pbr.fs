#version 330 core

out vec4 FragColor;


in vec2 UV;
in vec3 Normal;
in vec3 FragPosition;


uniform sampler2D albedo;
uniform sampler2D rougness;


void main()
{
	if (true)
	{
		FragColor = texture(rougness, UV);
	}
	else
	{
		FragColor = vec4(UV, 0.0f, 1.0f);
	}
}