#ifndef RENDERER_VERTEX_H
#define RENDERER_VERTEX_H

#include <Math/Vec3.h>

typedef struct
{
	Vec3 position;
} Vertex;

Vertex CreateVertex(Vec3 pPosition);

#endif