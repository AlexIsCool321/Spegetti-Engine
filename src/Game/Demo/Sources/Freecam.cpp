#include <Demo/Freecam.hpp>

#include <iostream>

namespace Demo
{
	void Freecam::OnCreate()
	{
		std::cout << "Freecam Created!" << std::endl;
	}

	void Freecam::OnUpdate()
	{
		std::cout << "Freecam Updated!" << std::endl;
	}

	void Freecam::OnDestroy()
	{
		std::cout << "Freecam Destroyed!" << std::endl;
	}
}