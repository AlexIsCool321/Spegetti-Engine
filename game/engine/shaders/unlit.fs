#version 330 core


in vec2 UV;

out vec3 FragColor;


uniform sampler2D Color;


void main()
{
	FragColor = texture(Color, UV);
}