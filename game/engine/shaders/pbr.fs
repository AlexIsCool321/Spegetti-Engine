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
uniform sampler2D roughness;
uniform sampler2D metallic;
uniform sampler2D ao;

uniform float height_scale = 0.01f;
uniform sampler2D height;

//uniform sampler2D emmision;
uniform float emmision = 0.0f;

vec2 ParallaxMapping(vec2 texCoords, vec3 viewDir)
{ 
    float depth =  texture(height, fs_in.UV).r;    
    vec2 p = viewDir.xy / viewDir.z * (depth * height_scale);
    return fs_in.UV - p;    
} 

void main()
{
	vec2 UV = ParallaxMapping(fs_in.UV, view_position);
	
	gPosition					= fs_in.Frag_Position;
	gAlbedo						= texture(albedo, UV) * base_color;
	
	gAO_Metallic_Roughness.r	= texture(ao, UV).r;
	gAO_Metallic_Roughness.g	= texture(metallic, UV).g;
	gAO_Metallic_Roughness.b	= texture(roughness, UV).b;
	//gAO_Metallic_Roughness.a 	= emmision; //texture(emmision, UV).r;
	
	gNormal = texture(normal, UV).rgb;
	gNormal = gNormal * 2.0 - 1.0;   
	//gNormal = normalize(fs_in.TBN * gNormal); 
}