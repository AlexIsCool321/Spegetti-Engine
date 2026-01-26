#include <Renderer/RenderServer.hpp>

namespace Renderer
{
	RenderServer::RenderServer(System::Window& window)
	{

	}

	RenderServer::~RenderServer()
	{

	}


	Mesh* RenderServer::CreateMesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, unsigned int shader)
	{
		return new Mesh();
	}
}