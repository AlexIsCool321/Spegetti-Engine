#ifndef RENDERER_MODEL_H
#define RENDERER_MODEL_H

#include <Renderer/Mesh.h>

#include <stdint.h>

#define MAX_MESH_COUNT 255

typedef struct
{
	Mesh** m_meshes;
	uint8_t m_meshCount;
} Model;

Model* CreateModel(Mesh** pMeshes, uint8_t pMeshCount);

void DrawModel(Model* pModel);

void DestroyModel(Model* pModel);

#endif