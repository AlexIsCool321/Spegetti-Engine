#include <Renderer/Shader.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>

Shader* CreateShader(const char* pVertex, const char* pFragment)
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

	Shader* result = (Shader*)CallPlugInFunction("PLUGIN_CreateShader", args);
	if (!result)
	{
		printf("ERROR : [ PLUGIN_CreateShader ] RETURNED NULL!\n");
		return NULL;
	}

	return result;
}

void SetTextureUniform(Shader* pShader, const char* pName, Texture* pTexture)
{
	{
		if (!pShader)	printf("ERROR : SHADER IS NULL!\n");
		if (!pName)		printf("ERROR : NAME IS NULL!\n");
		if (!pTexture)	printf("ERROR : TEXURE IS NULL!\n");

		if (!pTexture || !pName) return;
	}

	void* args[3] =
	{
		pShader,
		&pName,
		pTexture
	};

	CallPlugInFunction("PLUGIN_SetTextureUniform", args);
}