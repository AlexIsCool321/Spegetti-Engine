#include <Renderer/specific/GL/GL_RenderServer.hpp>

namespace Renderer
{
	namespace GL
	{
		GL_RenderServer::GL_RenderServer()
		{
			this->m_window = nullptr;
			this->m_currentCamera = nullptr;
		}

		GL_RenderServer::~GL_RenderServer()
		{

		}


		unsigned short GL_RenderServer::CreateShader(const char* type)
		{
			return 0;
		}


		Mesh* GL_RenderServer::CreateMesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, unsigned short shader)
		{
			return nullptr;
		}

			
		Model* GL_RenderServer::CreateEmptyModel()
		{
			return nullptr;
		}

		Model* GL_RenderServer::CreateModel(std::vector<Mesh*> meshes)
		{
			return nullptr;
		}


		Model* GL_RenderServer::LoadModel(const char* name)
		{
			return nullptr;
		}
	}
}