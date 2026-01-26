#include <Renderer/RenderServer.hpp>

namespace Renderer
{
	RenderServer::RenderServer(System::Window& window)
	{

	}

	RenderServer::~RenderServer()
	{
		
	}


	unsigned short RenderServer::CreateShader(const char* type)
	{
		return Renderer::CreateShader();
	}


	Mesh* RenderServer::CreateMesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, unsigned short shader)
	{
		return new Mesh();
	}
}