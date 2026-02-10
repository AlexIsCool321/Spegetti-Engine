#include <Renderer/Mesh.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdlib.h>

Mesh* CreateMesh(Vertex* vertices, unsigned long* indices, unsigned short shader)
{
	void* args[3] =
	{
		vertices, indices, &shader
	};

	return (Mesh*)CallPlugInFunction("PLUGIN_CreateMesh", args);
}

void DrawMesh(Mesh* mesh)
{
	void* args[1] =
	{
		mesh
	};

	CallPlugInFunction("PLUGIN_DrawMesh", args);
}

void DestroyMesh(Mesh* mesh)
{
	void* args[1] =
	{
		mesh
	};
	
	CallPlugInFunction("PLUGIN_DestroyMesh", args);
}