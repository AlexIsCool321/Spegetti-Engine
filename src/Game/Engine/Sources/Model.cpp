#include <Engine/Model.hpp>

namespace Engine
{
	void Model::OnCreate()
	{
		Logging::Log("Model Created!");
	}

	void Model::OnUpdate()
	{
		Logging::Log("Model Updated!");
	}

	void Model::OnDestroy()
	{
		Logging::Log("Model Destroyed!");
	}
}