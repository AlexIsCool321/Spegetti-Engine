#include <System/Renderer.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>
#include <stdlib.h>

Shader* LoadShader(const char* pType)
{
	void* args[1] =
	{
		&pType
	};

	Shader* result = (Shader*)CallPlugInFunction("PLUGIN_LoadShader", args);
	if (!result)
	{
		printf("ERROR : [ PLUGIN_LoadShader ] RETURNED NULL!\n");
		return NULL;
	}

	return result;
}


Model* LoadModel(const char* pName, const char* pFormat)
{
	void* args[2] =
	{
		&pName,
		&pFormat
	};

	Model* result = (Model*)CallPlugInFunction("PLUGIN_LoadModel", args);
	if (!result)
	{
		printf("ERROR : [ PLUGIN_LoadModel ] RETURNED NULL!\n");
		return NULL;
	}

	return result;
}