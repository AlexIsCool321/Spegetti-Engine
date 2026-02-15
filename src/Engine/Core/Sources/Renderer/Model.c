#include <Renderer/Model.h>

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

	return (Model*)CallPlugInFunction("PLUGIN_CreateModel", args);
}

void DrawModel(Model* pModel, Camera* pCamera)
{
	{
		if (!pModel) printf("ERROR : MODEL IS NULL!\n");
		if (!pCamera) printf("ERROR : CAMERA IS NULL!\n");

		if (!pModel || !pCamera) return;
	}

	void* args[2] =
	{
		pModel,
		pCamera
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