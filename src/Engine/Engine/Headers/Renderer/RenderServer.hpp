#ifndef RENDERER_RENDERSERVER_HPP
#define RENDERER_RENDERSERVER_HPP

#include <System/Window.hpp>

#include <vector>

#include <Renderer/Shader.hpp>

#include <Renderer/Vertex.hpp>
#include <Renderer/Mesh.hpp>

#include <Renderer/Model.hpp>

#include <Renderer/Camera.hpp>

namespace Renderer
{
	class RenderServer
	{
	private:
		System::Window* m_window;

		Renderer::Camera* m_currentCamera;

	public:
		RenderServer();
		virtual ~RenderServer();

		virtual void AssignWindow(System::Window* window);

		virtual unsigned short CreateShader(const char* type);

		virtual Mesh* CreateMesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, unsigned short shader);
		
		virtual Model* CreateEmptyModel();
		virtual Model* CreateModel(std::vector<Mesh*> meshes);

		virtual Model* LoadModel(const char* name);

		virtual Camera* GetCurrentCamera();
		virtual void SetCurrentCamera(Camera* camera);
	};
}

#endif