#include <Engine/Model.hpp>

#include <iostream>

namespace Engine
{
	void Model::OnCreate()
	{
		std::cout << "Model Created!" << std::endl;
	}

	void Model::OnUpdate()
	{
		std::cout << "Model Updated!" << std::endl;
	}

	void Model::OnDestroy()
	{
		std::cout << "Model Destroyed!" << std::endl;
	}
}