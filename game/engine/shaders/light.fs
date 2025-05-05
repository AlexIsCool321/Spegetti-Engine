#version 330 core
out vec4 FragColor;

in vec2 UV;

struct Point_Light
{
	vec3 Position;
	vec3 Color;
	
	float Constant;
	float Linear;
	float Quadratic;
};

#define NUMBER_OF_LIGHTS 10  
uniform Point_Light Point_Lights[NUMBER_OF_LIGHTS];

uniform vec3 View_Position;

uniform sampler2D gPosition;
uniform sampler2D gNormal;
uniform sampler2D gAlbedo;
uniform sampler2D gAO_Metallic_Roughness;

vec3 Calculate_Spot_Light(Point_Light Light, vec3 Albedo, vec3 Position, vec3 Normal, float Metallic, float Roughness, float AO)
{
	vec3 color;
	
	
	vec3 Light_Direction	= normalize(Light.Position - Position);
	vec3 View_Direction		= normalize(View_Position - Position);
	
	vec3 Normilized_Normal = normalize(Normal);
	
	//vec3 Half_Way_Direction = reflect(-Light_Direction, Normilized_Normal);
	vec3 Half_Way_Direction = normalize(View_Direction + Light_Direction);
	
	vec3 ambient = Light.Color;
	
	vec3 diffuse = Light.Color * max(dot(Normilized_Normal, Light_Direction), 0.0);
	
	vec3 specular = Roughness * pow(max(dot(Normilized_Normal, Half_Way_Direction), 0.0f), (1.0f - Roughness) * 256) * Light.Color;
	
	float ao = 1.0f - AO;
	
	float distance = length(Light.Position - Position);
	float attenuation = 1.0 / (Light.Constant + Light.Linear * distance + Light.Quadratic * (distance * distance));
	
	ambient		*= attenuation;
	diffuse		*= attenuation;
	specular	*= attenuation;
	
	color = (Albedo) * (ambient + diffuse + specular);
	
	
	if (color.x >= 0.0f && color.y >= 0.0f && color.z >= 0.0f)
	{
		return color;
	}
	else
	{
		return vec3(0.0f);
	}
}

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
	
	vec3 result = vec3(0.0f);
	
	for(int i = 0; i < NUMBER_OF_LIGHTS; i++)
	{
		result += Calculate_Spot_Light(Point_Lights[i], Albedo, Position, Normal, Metallic, Roughness, AO);
	}
	
	FragColor = vec4(result, 1.0);
}