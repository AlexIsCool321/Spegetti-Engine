#version 330 core
out vec4 FragColor;

in vec2 UV;

struct Light
{
	vec3 Position;
	vec3 Color;
	float Strength;
};

uniform Light light1;

uniform vec3 View_Position;

uniform sampler2D gPosition;
uniform sampler2D gNormal;
uniform sampler2D gAlbedo;
uniform sampler2D gAO_Metallic_Roughness;

void main()
{	
	vec3 Position	= texture(gPosition, UV).rgb;
	vec3 Albedo		= texture(gAlbedo, UV).rgb;
	vec3 Normal		= normalize(texture(gNormal, UV).rgb);
	
	vec4 AO_Metallic_Roughness = texture(gAO_Metallic_Roughness, UV);
	float AO		= AO_Metallic_Roughness.r;
	float Metallic	= AO_Metallic_Roughness.g;
	float Roughness	= AO_Metallic_Roughness.b;
	float Emmision	= AO_Metallic_Roughness.a;
	
	vec3 Light_Direction = normalize(light1.Position - Position);
	
	vec3 View_Direction = normalize(View_Position - Position);
	vec3 HalfWay_Direction = normalize(Light_Direction + View_Direction); 

	
	float ambient_strength =  0.1f;
	vec3 ambient = ambient_strength * light1.Color;
	
	vec3 diffuse = max(dot(Normal, Light_Direction), 0.0f) * light1.Color;
	
	float specular_strength = 0.5;
	vec3 specular = (Roughness * pow(max(dot(View_Direction, HalfWay_Direction), 0.0), Metallic * 256)) * light1.Color;  
	
	
	vec3 result = Albedo * (ambient + diffuse + specular);
	FragColor = vec4(result, 1.0f);
}