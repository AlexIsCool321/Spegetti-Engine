#include <Engine/Engine.hpp>

Properties* Init()
{
	Properties* properties = new Game::Properties();
	
	properties->title = "Engine";

	properties->entityRegistry = new Noodle::Registry();
	properties->entityRegistry->RegisterEntity<Engine::Model>("Model");

	return properties;
}
