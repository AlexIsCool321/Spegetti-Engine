#include <Engine/Model.hpp>

namespace Engine
{
	void Model::OnCreate()
	{
		Log("Created Model");
	}

	void Model::OnUpdate()
	{

	}

	void Model::OnDestroy()
	{
		Log("Destroyed Model");
	}
}