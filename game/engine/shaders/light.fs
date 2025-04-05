#version 330 core
out vec4 FragColor;

in vec2 UV;

uniform sampler2D gPosition;
uniform sampler2D gNormal;
uniform sampler2D gAlbedo_Roughness;

uniform int Mode = 0;

void main()
{
	vec3 Position = texture(gPosition, UV).rgb;
	vec3 Normal = texture(gNormal, UV).rgb;
    vec3 Albedo = texture(gAlbedo_Roughness, UV).rgb;
    float Roughness = texture(gAlbedo_Roughness, UV).a;
	
	if (Mode == 0) // Default
	{
		FragColor = vec4(Position, 1.0f);
	}
	if(Mode == 4) // Position
	{
		FragColor = vec4(Position, 1.0f);
	}
	if(Mode == 5) // Albedo
	{
		FragColor = vec4(Albedo, 1.0f);
	}
	if(Mode == 6) // Normal
	{
		FragColor = vec4(Normal, 1.0f);
	}
	if(Mode == 7) // Normal Map
	{
		FragColor = vec4(Normal, 1.0f);
	}
	if(Mode == 8) // Roughness
	{
		FragColor = vec4(Roughness);
	}
}