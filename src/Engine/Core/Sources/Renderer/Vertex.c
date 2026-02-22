#include <Renderer/Vertex.h>

Vertex CreateVertex(Vec3 pPosition, Vec2 pUV)
{
	Vertex result;

	result.position	= pPosition;
	result.uv		= pUV;

	return result;
}