#include <Engine/Model.hpp>

namespace Engine
{
	void Model::OnCreate()
	{
		this->LoadModel("cube.obj");
	}

	void Model::OnUpdate()
	{


	}

	void Model::OnDestroy()
	{
		Log("Destroyed Model");
	}


	void Model::LoadModel(const char* path)
	{
		// Cleanup previous model
		if (this->m_model != nullptr) delete this->m_model;

		this->m_model = Global_Properties->renderServer->CreateEmptyModel();
	}
}