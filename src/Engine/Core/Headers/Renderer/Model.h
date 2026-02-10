#ifndef RENDERER_MODEL_H
#define RENDERER_MODEL_H

#include <Renderer/Mesh.h>

typedef struct
{
	Mesh** meshes;
	unsigned long meshCount;
} Model;

Model* CreateModel(Mesh** meshes, unsigned long meshCount);

void DrawModel(Model* mesh);

void DestroyModel(Model* mesh);

#endif