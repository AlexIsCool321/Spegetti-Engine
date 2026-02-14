#include <Renderer/Shader.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>

uint8_t CreateShader(const char* pVertex, const char* pFragment)
{
	{
		if (!pVertex)	printf("ERROR : VERTEX SHADER IS NULL!\n");
		if (!pFragment)	printf("ERROR : FRAGMENT SHADER IS NULL!\n");

		if (!pVertex || !pFragment) return 0;
	}

	void* args[2] =
	{
		&pVertex,
		&pFragment
	};

	intptr_t result = (intptr_t)CallPlugInFunction("PLUGIN_CreateShader", args);
	return (uint8_t)result;
}