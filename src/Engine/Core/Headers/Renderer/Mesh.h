#ifndef RENDERER_MESH_H
#define RENDERER_MESH_H

#include <Renderer/Vertex.h>

typedef struct
{
	
} Mesh;

Mesh* CreateMesh(Vertex* vertices, unsigned long* indices, unsigned short shader);

void DrawMesh(Mesh* mesh);

void DestroyMesh(Mesh* mesh);

#endif