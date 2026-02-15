#include <MGL_Renderer/Model.h>

#include <MGL_Renderer/Mesh.h>
#include <Renderer/Model.h>

#include <stdio.h>
#include <stdlib.h>

void* PLUGIN_CreateModel(void** pArgs)
{
	Mesh** pMeshes;
	uint8_t pMeshCount;
	
	{
		if (!pArgs[0]) printf("ERROR [PLUGIN] : MESH LIST IS NULL!\n");
		if (!pArgs[1]) printf("ERROR [PLUGIN] : MESH COUNT IS NULL!\n");

		if (!pArgs[0] || !pArgs[1]) return NULL;

		pMeshes		= (Mesh**)pArgs[0];
		pMeshCount	= *(uint8_t*)pArgs[1];
	}

	Model* result = (Model*)malloc(sizeof(Model));
	if (!result)
	{
		printf("ERROR [PLUGIN] : FAILED TO ALLOCATE MEMORY FOR MODEL!");
		return NULL;
	}

	result->m_meshes = (Mesh**)malloc(sizeof(MGL_Mesh) * pMeshCount);
	if (!result->m_meshes)
	{
		printf("ERROR [PLUGIN] : FAILED TO ALLOCATE MEMORY FOR MODEL MESHES!");
		return NULL;
	}


	result->m_meshCount = pMeshCount;

	for (uint8_t i = 0; i < pMeshCount; i++)
	{
		result->m_meshes[i] = pMeshes[i];
	}

	return (void*)result;
}

void PLUGIN_DrawModel(void** pArgs)
{
	Model* pModel;

	{
		if (!pArgs[0]) printf("ERROR [PLUGIN] : MODEL IS NULL!\n");

		if (!pArgs[0]) return;

		pModel = (Model*)pArgs[0];
	}

	for (uint8_t i = 0; i < pModel->m_meshCount; i++)
	{
		DrawMesh(pModel->m_meshes[i]);
	}
}

void PLUGIN_DestroyModel(void** pArgs)
{
	Model* pModel;

	{
		if (!pArgs[0]) printf("WARN [PLUGIN] : Model is already NULL.\n");

		if (!pArgs[0]) return;

		pModel = (Model*)pArgs[0];
	}

	for (uint8_t i = 0; i < pModel->m_meshCount; i++)
	{
		DestroyMesh(pModel->m_meshes[i]);
	}

	free(pModel);
	pArgs[0] = NULL;
}