#version 330 core
out vec4 FragColor;

in vec2 UV;

// texture samplers
uniform sampler2D albedo;
uniform sampler2D roughness;
uniform sampler2D normal;

void main()
{
	FragColor = texture(albedo, UV);
}