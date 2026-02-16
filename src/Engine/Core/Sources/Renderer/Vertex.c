#include <Renderer/Vertex.h>

Vertex CreateVertex(Vec3 pPosition)
{
	Vertex result;

	result.position = pPosition;

	return result;
}