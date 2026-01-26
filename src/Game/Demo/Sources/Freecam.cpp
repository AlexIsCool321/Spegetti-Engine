#include <Demo/Freecam.hpp>

#include <Logging/Logging.hpp>

namespace Demo
{
	void Freecam::OnCreate()
	{
		Logging::Log("Freecam Created!");
	}

	void Freecam::OnUpdate()
	{
		Logging::Log("Freecam Updated!");
	}

	void Freecam::OnDestroy()
	{
		Logging::Log("Freecam Destroyed!");
	}
}