#include <Renderer/Mesh.h>
#include <Renderer/Camera.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>
#include <stdlib.h>

Mesh* CreateMesh(Vertex* pVertices, unsigned int pVertexSize, unsigned int* pIndices, unsigned int pIndicesSize, Shader* pShader)
{
	{
		if (!pVertices) printf("ERROR : VERTICES IS NULL!\n");
		if (!pIndices) printf("ERROR : INDICES IS NULL!\n");
		if (!pShader) printf("ERROR : SHADER IS NULL!\n");

		if (!pVertices || !pIndices || !pShader) return NULL;
	}

	void* args[5] =
	{
		pVertices,
		&pVertexSize,
		pIndices,
		&pIndicesSize,
		pShader
	};

	Mesh* result = (Mesh*)CallPlugInFunction("PLUGIN_CreateMesh", args);
	if (!result)
	{
		printf("ERROR : [ PLUGIN_CreateMesh ] RETURNED NULL!\n");
		return NULL;
	}

	return result;
}

void DrawMesh(Mesh* pMesh)
{
	if (!GetCurrentCamera()) return;
	
	{
		if (!pMesh) printf("ERROR : MESH IS NULL!\n");

		if (!pMesh) return;
	}

	void* args[1] =
	{
		pMesh
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