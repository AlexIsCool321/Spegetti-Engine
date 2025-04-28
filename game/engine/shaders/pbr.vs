#version 330 core

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aUV;
layout (location = 3) in vec3 aTangent;
layout (location = 4) in vec3 aBitangent;


out VS_OUT {
	vec3 Frag_Position;
	vec2 UV;
	vec3 Normal;
	//mat3 TBN;
} vs_out;  


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position		= projection * view * model * vec4(aPosition, 1.0);
	vs_out.Frag_Position	= vec3(model * vec4(aPosition, 1.0));
	vs_out.UV				= aUV;
	vs_out.Normal			= mat3(transpose(inverse(model))) * aNormal;  
	
	//vec3 T = normalize(vec3(model * vec4(aTangent,   0.0)));
	//vec3 B = normalize(vec3(model * vec4(aBitangent, 0.0)));
	//vec3 N = normalize(vec3(model * vec4(aNormal,    0.0)));
	//vs_out.TBN = mat3(T, B, N);
}