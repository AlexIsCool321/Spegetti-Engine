#include <Renderer/Mesh.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>
#include <stdlib.h>

Mesh* CreateMesh(Vertex* pVertices, unsigned int pVertexSize, unsigned int* pIndices, unsigned int pIndicesSize, unsigned int pShader)
{
	{
		if (!pVertices) printf("ERROR : VERTICES IS NULL!\n");
		if (!pIndices) printf("ERROR : INDICES IS NULL!\n");

		if (!pVertices || !pIndices) return NULL;
	}

	void* args[5] =
	{
		pVertices,
		&pVertexSize,
		pIndices,
		&pIndicesSize,
		&pShader
	};

	void* result = CallPlugInFunction("PLUGIN_CreateMesh", args);

	return (Mesh*)result;
}

void DrawMesh(Mesh* pMesh, Camera* pCamera)
{
	{
		if (!pMesh) printf("ERROR : MESH IS NULL!\n");
		if (!pCamera) printf("ERROR : CAMERA IS NULL!\n");

		if (!pMesh || !pCamera) return;
	}

	void* args[2] =
	{
		pMesh,
		pCamera
	};

	CallPlugInFunction("PLUGIN_DrawMesh", args);
}

void DestroyMesh(Mesh* pMesh)
{
	{
		if (!pMesh) printf("ERROR : MESH IS NULL!\n");

		if (!pMesh) return;
	}

	void* args[1] =
	{
		pMesh
	};

	CallPlugInFunction("PLUGIN_DestroyMesh", args);
}