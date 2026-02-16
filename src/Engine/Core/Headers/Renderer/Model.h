#ifndef RENDERER_MODEL_H
#define RENDERER_MODEL_H

#include <Renderer/Mesh.h>

#include <stdint.h>

typedef struct
{
	Mesh** m_meshes;
	uint8_t m_meshCount;
} Model;

Model* CreateModel(Mesh** pMeshes, uint8_t pMeshCount);

void DrawModel(Model* pModel, Camera* pCamera);

void DestroyModel(Model* pModel);

#endif