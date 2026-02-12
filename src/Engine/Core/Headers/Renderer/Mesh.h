#ifndef RENDERER_MESH_H
#define RENDERER_MESH_H

#include <Renderer/Vertex.h>

typedef struct
{
	
} Mesh;

Mesh* CreateMesh(Vertex* vertices, unsigned long vertices_size, unsigned long* indices, unsigned long indices_size, unsigned short shader);

void DrawMesh(Mesh* mesh);

void DestroyMesh(Mesh* mesh);

#endif