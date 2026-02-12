#ifndef RENDERER_VERTEX_H
#define RENDERER_VERTEX_H

#include <Math/Math.h>

typedef struct
{
	Vec3 position;
} Vertex;

Vertex CreateVertex(Vec3 position);

#endif