#include <MGL_Renderer/Shader.h>

#include <MGL_Renderer/Texture.h>

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

		pVertexShaderSource		= *(const char**)pArgs[0];
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
	unsigned int shader = glCreateProgram();

	glAttachShader(shader, vertexShader);
	glAttachShader(shader, fragmentShader);
	glLinkProgram(shader);

	glGetProgramiv(shader, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(shader, sizeof(errorLog), NULL, errorLog);
		printf("ERROR [PLUGIN] : FAILED TO LINK SHADERS! : [ %s ]\n", errorLog);

		return NULL;
	}

	glUseProgram(shader);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	MGL_Shader* result = (MGL_Shader*)malloc(sizeof(MGL_Shader));
	if (!result)
	{
		printf("ERROR : FAILED TO ALLOCATE MEMORY FOR SHADER!\n");
		return NULL;
	}

	result->id = shader;

	return (void*)result;
}

void PLUGIN_SetTextureUniform(void** pArgs)
{
	MGL_Shader* pShader;
	const char* pName;
	MGL_Texture* pTexture;

	{
		if (!pArgs[0]) printf("ERROR [PLUGIN] : SHADER IS NULL!\n");
		if (!pArgs[1]) printf("ERROR [PLUGIN] : NAME IS NULL!\n");
		if (!pArgs[2]) printf("ERROR [PLUGIN] : TEXTURE IS NULL!\n");

		if (!pArgs[0] || !pArgs[1]) return;

		pShader		=	 (MGL_Shader*)	pArgs[0];
		pName		=	*(const char**)	pArgs[1];
		pTexture	=	 (MGL_Texture*)	pArgs[2];
	}

	glUniform1i(glGetUniformLocation(pShader->id, pName), pTexture->id);
}