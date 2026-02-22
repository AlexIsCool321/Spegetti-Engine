#include <Renderer/Model.h>
#include <Renderer/Camera.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>
#include <stdlib.h>

Model* CreateModel(Mesh** pMeshes, uint8_t pMeshCount)
{
	{
		if (!pMeshes) printf("ERROR : MESH LIST IS NULL!\n");

		if (!pMeshes) return NULL;
	}

	void* args[2] =
	{
		pMeshes,
		&pMeshCount
	};

	Model* result = (Model*)CallPlugInFunction("PLUGIN_CreateModel", args);
	if (!result)
	{
		printf("ERROR : [ PLUGIN_CreateModel ] RETURNED NULL!\n");
		return NULL;
	}

	return result;
}

void DrawModel(Model* pModel)
{
	if (!GetCurrentCamera()) return;
	
	{
		if (!pModel) printf("ERROR : MODEL IS NULL!\n");

		if (!pModel) return;
	}

	void* args[1] =
	{
		pModel
	};

	CallPlugInFunction("PLUGIN_DrawModel", args);
}

void DestroyModel(Model* pModel)
{
	{
		if (!pModel) printf("WARN : Model is already NULL.\n");

		if (!pModel) return;
	}

	void* args[1] =
	{
		pModel
	};

	CallPlugInFunction("PLUGIN_DestroyModel", args);
}