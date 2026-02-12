#include <Renderer/Mesh.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>
#include <stdlib.h>

Mesh* CreateMesh(Vertex* vertices, unsigned long vertices_size, unsigned long* indices, unsigned long indices_size, unsigned short shader)
{
	{
		if (!vertices) printf("ERROR : VERTICES IS NULL!\n");
		if (!indices) printf("ERROR : INDICES IS NULL!\n");
		
		if (!vertices || !indices) return NULL;
	}
	
	void* args[5] =
	{
		vertices, &vertices_size, indices, &indices_size, &shader
	};
 
	return (Mesh*)CallPlugInFunction("PLUGIN_CreateMesh", args);
}

void DrawMesh(Mesh* mesh)
{
	{
		if (!mesh) printf("ERROR : MESH IS NULL!\n");
		
		if (!mesh) return;
	}

	void* args[1] =
	{
		mesh
	};

	CallPlugInFunction("PLUGIN_DrawMesh", args);
}

void DestroyMesh(Mesh* mesh)
{
	{
		if (!mesh) printf("WARN : Mesh is already NULL.\n");
		
		if (!mesh) return;
	}

	void* args[1] =
	{
		mesh
	};
	
	CallPlugInFunction("PLUGIN_DestroyMesh", args);
}