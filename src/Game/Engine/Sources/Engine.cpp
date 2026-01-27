#include <Engine/Engine.hpp>

extern "C"
{
	Properties* Init()
	{
		Properties* properties = new Game::Properties();
		
		properties->title = "Engine";

		properties->entityRegistry = new Noodle::Registry();
		properties->entityRegistry->RegisterEntity<Engine::Model>("Model");

		Global_Properties = properties;
		return properties;
	}

	void UpdateProperties(Game::Properties* properties)
	{
		Global_Properties = properties;
	}
}