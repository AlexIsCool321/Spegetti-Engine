#include <Demo/Demo.hpp>

Game::Properties* Init()
{
	Game::Properties* properties = new Game::Properties();
	
	properties->title = "Demo";

	properties->registry = new Noodle::Registry();
	properties->registry->RegisterEntity<Demo::Freecam>("Freecam");

	return properties;
}