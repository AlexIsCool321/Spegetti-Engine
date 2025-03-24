#version 330 core

layout (location = 0) out vec3 gPosition;
layout (location = 1) out vec3 gNormal;
layout (location = 2) out vec4 gAlbedo_Roughness;


in vec2 UV;
in vec3 Normal;
in vec3 Frag_Position;


struct Material
{
	sampler2D albedo;
	vec3 base_color;
	
	sampler2D normal;
	
	sampler2D roughness;
	float roughness_strength;
	
	sampler2D height;
	float height_scale;
};


uniform Material material;


void main()
{
	gPosition				= Frag_Position;
	gNormal					= normalize(Normal);
	gAlbedo_Roughness.rgb	= texture(material.albedo, UV).rgb;
	gAlbedo_Roughness.a		= texture(material.albedo, UV).r;
}