#version 330 core
out vec4 FragColor;

in vec2 UV;

uniform sampler2D gPosition;
uniform sampler2D gNormal;
uniform sampler2D gAlbedo_Roughness;


void main()
{
	vec3 Position = texture(gPosition, UV).rgb;
	vec3 Normal = texture(gNormal, UV).rgb;
    vec3 Albedo = texture(gAlbedo_Roughness, UV).rgb;
    float Roughness = texture(gAlbedo_Roughness, UV).a;
	
	FragColor = vec4(Normal, 1.0f);
}