#include <Renderer/Model.h>

#include <PlugNPlay/PlugNPlay.h>

Model* CreateModel(Mesh** meshes, unsigned long meshCount)
{
	void* args[2] =
	{
		meshes, &meshCount
	};

	return (Model*)CallPlugInFunction("PLUGIN_CreateModel", args);
}


void DrawModel(Model* mesh)
{
	void* args[1] =
	{
		mesh
	};

	CallPlugInFunction("PLUGIN_DrawModel", args);
}


void DestroyModel(Model* mesh)
{
	void* args[1] =
	{
		mesh
	};

	CallPlugInFunction("PLUGIN_DestroyModel", args);
}