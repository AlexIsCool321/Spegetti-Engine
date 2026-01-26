#include <Renderer/Model.hpp>

namespace Renderer
{
	Model::Model()
	{

	}

	Model::~Model()
	{
		for (Mesh* mesh : this->m_meshes)
		{
			delete mesh;
		}

		this->m_meshes.clear();
		this->m_meshes.shrink_to_fit();
	}


	void Model::AddMesh(Mesh* mesh)
	{
		this->m_meshes.push_back(mesh);
	}


	void Model::Draw()
	{
		for (Mesh* mesh : this->m_meshes)
		{
			mesh->Draw();
		}
	}
}