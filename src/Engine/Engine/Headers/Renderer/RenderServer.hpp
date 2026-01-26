#ifndef RENDERER_RENDERSERVER_HPP
#define RENDERER_RENDERSERVER_HPP

#include <System/Window.hpp>

#include <vector>

#include <Renderer/Shader.hpp>

#include <Renderer/Vertex.hpp>
#include <Renderer/Mesh.hpp>

namespace Renderer
{
	class RenderServer
	{
	public:
		RenderServer(System::Window& window);
		virtual ~RenderServer();

		virtual unsigned short CreateShader(const char* type);

		virtual Mesh* CreateMesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, unsigned short shader);
	};
}

#endif