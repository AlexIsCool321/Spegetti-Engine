#ifndef RENDERER_GL_RENDERSERVER_HPP
#define RENDERER_GL_RENDERSERVER_HPP

#include <Renderer/RenderServer.hpp>

// TODO : Covert the following to OpenGL
#include <Renderer/Shader.hpp>

#include <Renderer/Vertex.hpp>
#include <Renderer/Mesh.hpp>

#include <Renderer/Model.hpp>

#include <Renderer/Camera.hpp>

namespace Renderer
{
	namespace GL
	{
		class GL_RenderServer : public RenderServer
		{
		public:
			GL_RenderServer();
			~GL_RenderServer();

			unsigned short CreateShader(const char* type);

			Mesh* CreateMesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, unsigned short shader);
			
			Model* CreateEmptyModel();
			Model* CreateModel(std::vector<Mesh*> meshes);

			Model* LoadModel(const char* name);
		};
	}
}

#endif