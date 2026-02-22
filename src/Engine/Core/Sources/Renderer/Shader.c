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

void SetTextureUniform(unsigned int pShader, Texture* pTexture)
{
	{
		if (!pTexture)	printf("ERROR : TEXURE IS NULL!\n");

		if (!pTexture) return;
	}

	void* args[1] =
	{
		pTexture
	};

	CallPlugInFunction("PLUGIN_SetTextureUniform", args);
}