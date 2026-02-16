#ifndef MGL_RENDERER_MESH_H
#define MGL_RENDERER_MESH_H

#include <Renderer/Mesh.h>

typedef struct
{
	unsigned int m_VBO;
	unsigned int m_VAO;
	unsigned int m_EBO;

	unsigned int m_shader;

	unsigned int m_IndicesSize;
} MGL_Mesh;

void* PLUGIN_CreateMesh(void** pArgs);

void PLUGIN_DrawMesh(void** pArgs);

void PLUGIN_DestroyMesh(void** pArgs);

#endif