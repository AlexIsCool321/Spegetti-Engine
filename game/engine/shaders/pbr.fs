#version 330 core

layout (location = 0) out vec3 gPosition;
layout (location = 1) out vec3 gNormal;
layout (location = 2) out vec4 gAlbedo_Roughness;


in vec2 UV;
in vec3 Normal;
in vec3 Frag_Position;

uniform sampler2D albedo;

uniform sampler2D normal;

uniform sampler2D roughness;

uniform sampler2D height;


void main()
{
	gPosition				= Frag_Position;
	gNormal					= gNormal; //texture(normal, UV).rgb;
	gAlbedo_Roughness.rgb	= texture(albedo, UV).rgb;
	gAlbedo_Roughness.a		= texture(roughness, UV).r;
}