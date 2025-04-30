#version 330 core

out vec3 FragColor;

uniform vec3 Color = vec3(0.8f);

void main()
{
	FragColor = Color;
}