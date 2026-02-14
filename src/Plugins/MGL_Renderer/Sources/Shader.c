#include <GL_Renderer/Shader.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void* PLUGIN_CreateShader(void** pArgs)
{
	const char* vertexShader;
	const char* fragmentShader;

	{
		if (!pArgs[0]) printf("ERROR [PLUGIN] : VERTEX SHADER IS NULL!\n");
		if (!pArgs[1]) printf("ERROR [PLUGIN] : FRAGMENT SHADER IS NULL!\n");

		if (!pArgs[0] || !pArgs[1]) return NULL;

		vertexShader	= *(const char**)pArgs[0];
		fragmentShader	= *(const char**)pArgs[1];
	}

	uint8_t result = 0;

	return (void*)(intptr_t)result;
}