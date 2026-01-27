#include <Engine/Model.hpp>

namespace Engine
{
	void Model::OnCreate()
	{
		this->m_model = Global_Properties->renderServer->CreateEmptyModel();
	}

	void Model::OnUpdate()
	{
		this->m_model->Draw();
	}

	void Model::OnDestroy()
	{
		delete this->m_model;
	}
}