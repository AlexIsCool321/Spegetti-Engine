#ifndef RENDERER_RENDERSERVER_HPP
#define RENDERER_RENDERSERVER_HPP

#include <System/Window.hpp>

#include <vector>

#include <Renderer/Vertex.hpp>
#include <Renderer/Mesh.hpp>

namespace Renderer
{
	class RenderServer
	{
	public:
		RenderServer(System::Window& window);
		virtual ~RenderServer();

		virtual Mesh* CreateMesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, unsigned int shader);
	};
}

#endif