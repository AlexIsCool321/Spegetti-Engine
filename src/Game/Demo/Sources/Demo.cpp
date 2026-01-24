#include <Demo/Demo.hpp>

Game::Properties* Init()
{
	Game::Properties* properties = new Game::Properties();
	
	properties->title = "Demo";

	properties->entityRegistry = new Noodle::Registry();
	properties->entityRegistry->RegisterEntity<Demo::Freecam>("Freecam");

	return properties;
}