#ifndef RENDERER_MESH_H
#define RENDERER_MESH_H

#include <Renderer/Vertex.h>

typedef struct
{

} Mesh;

Mesh* CreateMesh(Vertex* pVertices, unsigned int pVertexSize, unsigned int* pIndices, unsigned int pIndicesSize, unsigned int shader);

#endif