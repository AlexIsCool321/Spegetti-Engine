#include <Demo/Demo.hpp>

Game::Properties* Init()
{
	Game::Properties* properties = new Game::Properties();
	
	properties->title = "Demo";

	return properties;
}