#version 330 core

layout (location = 0) out vec3 gPosition;
layout (location = 1) out vec3 gNormal;
layout (location = 2) out vec4 gAlbedo;
layout (location = 3) out vec4 gAO_Metallic_Roughness;



in VS_OUT {
    vec3 Frag_Position;
    vec2 UV;
	vec3 Normal;
	
    //mat3 TBN;
} fs_in; 

uniform vec3 view_position;

uniform sampler2D albedo;
uniform vec4 base_color = vec4(1.0f);

uniform sampler2D normal;
uniform sampler2D arm;

uniform sampler2D height;

//uniform sampler2D emmision;
uniform float emmision = 0.0f;

vec2 ParallaxMapping(float height_scale, vec3 view_direction)
{ 
	float depth	= texture(height, fs_in.UV).r;    
	vec2 p		= view_direction.xy / view_direction.z * (depth * height_scale);
	return fs_in.UV - p;    
} 

void main()
{
	vec2 UV = fs_in.UV; //ParallaxMapping(0.01f, view_position);
	
	gPosition					= fs_in.Frag_Position;
	gAlbedo						= texture(albedo, UV) * base_color;
	
	gAO_Metallic_Roughness.rgb	= texture(arm, UV).rgb;
	gAO_Metallic_Roughness.a 	= emmision; //texture(emmision, UV).r;
	
	gNormal = texture(normal, UV).rgb;
	gNormal = gNormal * 2.0 - 1.0;   
	//gNormal = normalize(fs_in.TBN * gNormal); 
}