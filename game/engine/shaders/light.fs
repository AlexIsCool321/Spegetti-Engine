#version 330 core
out vec4 FragColor;

in vec2 UV;

struct Light
{
	vec3 Position;
	vec3 Color;
	
	float Constant;
	float Linear;
	float Quadratic;
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
	
	vec3 ambient = light1.Color;
	 
	vec3 Normalized_Normal = normalize(Normal);
	vec3 Light_Direction = normalize(light1.Position - Position);
	
	vec3 diffuse = light1.Color * max(dot(Normalized_Normal, Light_Direction), 0.0);

	vec3 View_Direction = normalize(View_Position - Position);
	vec3 Reflect_Direction = reflect(-Light_Direction, Normalized_Normal);
	
	vec3 specular = light1.Color * pow(max(dot(View_Direction, Reflect_Direction), 0.0), Metallic * 256) * Roughness;

	float distance= length(light1.Position - Position);
	float attenuation = 1.0 / (light1.Constant + light1.Linear * distance + light1.Quadratic * (distance * distance));

	ambient		*= attenuation;
	diffuse		*= attenuation;
	specular	*= attenuation; 

	vec3 result = Albedo * (ambient + diffuse + specular);
	FragColor = vec4(result, 1.0);
}