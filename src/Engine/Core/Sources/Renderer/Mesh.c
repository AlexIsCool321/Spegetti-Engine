#include <Renderer/Mesh.h>

#include <PlugNPlay/PlugNPlay.h>

Mesh* CreateMesh(Vertex* pVertices, unsigned int pVertexSize, unsigned int* pIndices, unsigned int pIndicesSize, unsigned int shader)
{
	void* args[5] =
	{
		pVertices,
		&pVertexSize,
		pIndices,
		&pIndicesSize,
		&shader
	};

	void* result = CallPlugInFunction("PLUGIN_CreateMesh", args);

	return (Mesh*)result;
}