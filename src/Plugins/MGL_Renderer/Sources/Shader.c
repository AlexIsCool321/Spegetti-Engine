#include <MGL_Renderer/Shader.h>

#include <glad/gl.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void* PLUGIN_CreateShader(void** pArgs)
{
	const char* pVertexShaderSource;
	const char* pFragmentShaderSource;

	{
		if (!pArgs[0]) printf("ERROR [PLUGIN] : VERTEX SHADER IS NULL!\n");
		if (!pArgs[1]) printf("ERROR [PLUGIN] : FRAGMENT SHADER IS NULL!\n");

		if (!pArgs[0] || !pArgs[1]) return NULL;

		pVertexShaderSource	= *(const char**)pArgs[0];
		pFragmentShaderSource	= *(const char**)pArgs[1];
	}

	int success;
	char errorLog[512];
	

	// Vertex
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &pVertexShaderSource, NULL);
	glCompileShader(vertexShader);

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(vertexShader, sizeof(errorLog), NULL, errorLog);
		printf("ERROR [PLUGIN] : FAILED TO COMPILE VERTEX SHADER! : [ %s ]\n", errorLog);

		return NULL;
	}
	
	// Fragment
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentShader, 1, &pFragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(fragmentShader, sizeof(errorLog), NULL, errorLog);
		printf("ERROR [PLUGIN] : FAILED TO COMPILE FRAGMENT SHADER! : [ %s ]\n", errorLog);

		return NULL;
	}


	// Parent Shader
	unsigned int result = glCreateProgram();

	glAttachShader(result, vertexShader);
	glAttachShader(result, fragmentShader);
	glLinkProgram(result);

	glGetProgramiv(result, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(result, sizeof(errorLog), NULL, errorLog);
		printf("ERROR [PLUGIN] : FAILED TO LINK SHADERS! : [ %s ]\n", errorLog);

		return NULL;
	}

	glUseProgram(result);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return (void*)(intptr_t)result;
}