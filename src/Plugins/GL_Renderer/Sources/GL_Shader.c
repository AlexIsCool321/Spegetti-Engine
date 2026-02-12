#include <GL_Renderer/GL_Shader.h>

#include <glad/gl.h>

#include <string.h>

#include <stdio.h>
#include <stdlib.h>

unsigned short* PLUGIN_CreateShader(void** args)
{
	const char* vertexShaderSource;
	const char* fragmentShaderSource;

	{
		if (!args[0]) printf("ERROR [PLUGIN] : VERTEX SHADER LENGTH IS NULL!\n");
		if (!args[1]) printf("ERROR [PLUGIN] : VERTEX SHADER IS NULL!\n");

		if (!args[2]) printf("ERROR [PLUGIN] : FRAGMENT SHADER LENGTH IS NULL!\n");
		if (!args[3]) printf("ERROR [PLUGIN] : FRAGMENT SHADER IS NULL!\n");

		if (!args[0] || !args[1] || !args[2] || !args[3]) return 0;

		vertexShaderSource		= (const char*)args[0];
		fragmentShaderSource	= (const char*)args[2];
	}

	int success;
	char errorLog[512];

	// Vertex Shader
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(vertexShader, sizeof(errorLog), NULL, errorLog);
		printf("ERROR : FAILED TO COMPILE VERTEX SHADER! : [ %s ]\n", errorLog);
	}


	// Fragment Shader
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(fragmentShader, sizeof(errorLog), NULL, errorLog);
		printf("ERROR : FAILED TO COMPILE FRAGMENT SHADER! : [ %s ]\n", errorLog);
	}


	// Parent Shader
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(shaderProgram, sizeof(errorLog), NULL, errorLog);
		printf("ERROR : FAILED TO LINK SHADERS! : [ %s ]\n", errorLog);
	}

	// CleanUp
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);  

	glUseProgram(shaderProgram);


	unsigned short* result = (unsigned short*)malloc(sizeof(unsigned short));

	*result = shaderProgram;

	return result;
}
