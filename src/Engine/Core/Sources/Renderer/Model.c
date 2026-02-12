#include <Renderer/Model.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdlib.h>
#include <stdio.h>

Model* CreateModel(Mesh** meshes, unsigned long meshCount)
{
	{
		if (!meshes) printf("ERROR : MESHES IS NULL!\n");

		if (!meshes) return NULL;
	}

	void* args[2] =
	{
		meshes, &meshCount
	};

	void* result = CallPlugInFunction("PLUGIN_CreateModel", args);

	if (!result)
	{
		printf("ERROR : FAILED TO CREATE MODEL!\n");
		return NULL;
	}

	return (Model*)result;
}


void DrawModel(Model* mesh)
{
	{
		if (!mesh) printf("ERROR : MODEL IS NULL!\n");

		if (!mesh) return;
	}

	void* args[1] =
	{
		mesh
	};

	CallPlugInFunction("PLUGIN_DrawModel", args);
}


void DestroyModel(Model* mesh)
{
	{
		if (!mesh) printf("WARN : Model is already NULL.\n");

		if (!mesh) return;
	}

	void* args[1] =
	{
		mesh
	};

	CallPlugInFunction("PLUGIN_DestroyModel", args);
}