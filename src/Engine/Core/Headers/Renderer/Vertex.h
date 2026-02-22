#ifndef RENDERER_VERTEX_H
#define RENDERER_VERTEX_H

#include <Math/Vec3.h>
#include <Math/Vec2.h>

typedef struct
{
	Vec3 position;
	Vec2 uv;
} Vertex;

Vertex CreateVertex(Vec3 pPosition, Vec2 pUV);

#endif