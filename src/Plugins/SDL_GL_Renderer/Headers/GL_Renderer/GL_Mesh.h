#ifndef RENDERER_GL_MESH_H
#define RENDERER_GL_MESH_H

#include <Renderer/Mesh.h>

typedef struct
{
	Mesh* base;
} GL_Mesh;

Mesh* PLUGIN_CreateMesh(void** args);

void PLUGIN_DrawMesh(void** args);

void PLUGIN_DestroyMesh(void** args);

#endif