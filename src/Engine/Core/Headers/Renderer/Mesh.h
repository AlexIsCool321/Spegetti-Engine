#ifndef RENDERER_MESH_H
#define RENDERER_MESH_H

#include <Renderer/Vertex.h>
#include <Renderer/Camera.h>

typedef struct
{

} Mesh;

Mesh* CreateMesh(Vertex* pVertices, unsigned int pVertexSize, unsigned int* pIndices, unsigned int pIndicesSize, unsigned int pShader);

void DrawMesh(Mesh* pMesh);

void DestroyMesh(Mesh* pMesh);

#endif