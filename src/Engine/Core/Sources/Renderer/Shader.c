#include <Renderer/Shader.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>

unsigned int CreateShader(const char* pVertex, const char* pFragment)
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
	return (unsigned int)result;
}

void SetTextureUniform(unsigned int pShader, const char* pName, Texture* pTexture)
{
	{
		if (!pName)		printf("ERROR : NAME IS NULL!\n");
		if (!pTexture)	printf("ERROR : TEXURE IS NULL!\n");

		if (!pTexture || !pName) return;
	}

	void* args[3] =
	{
		&pShader,
		&pName,
		pTexture
	};

	CallPlugInFunction("PLUGIN_SetTextureUniform", args);
}