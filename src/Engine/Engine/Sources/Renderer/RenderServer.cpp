#include <Renderer/RenderServer.hpp>

namespace Renderer
{
	RenderServer::RenderServer()
	{
		this->m_window = nullptr;
	}

	RenderServer::~RenderServer()
	{

	}


	void RenderServer::AssignWindow(System::Window* window)
	{
		this->m_window = window;
	}


	unsigned short RenderServer::CreateShader(const char* type)
	{
		return Renderer::CreateShader();
	}


	Mesh* RenderServer::CreateMesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, unsigned short shader)
	{
		return new Mesh();
	}


	Model* RenderServer::CreateEmptyModel()
	{
		return new Model();
	}

	Model* RenderServer::CreateModel(std::vector<Mesh*> meshes)
	{
		Model* result = new Model();

		for (Mesh* mesh : meshes)
		{
			result->AddMesh(mesh);
		}

		return result;
	}

	
	Model* RenderServer::LoadModel(const char* name)
	{
		return new Model();
	}


	Camera* RenderServer::GetCurrentCamera()
	{
		return this->m_currentCamera;
	}

	void RenderServer::SetCurrentCamera(Camera* camera)
	{
		this->m_currentCamera = camera;
	}
}