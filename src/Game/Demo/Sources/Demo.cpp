#include <Demo/Demo.hpp>

extern "C"
{
	Game::Properties* Init()
	{
		Game::Properties* properties = new Game::Properties();
		
		properties->title = "Demo";

		properties->entityRegistry = new Noodle::Registry();
		properties->entityRegistry->RegisterEntity<Demo::Freecam>("Freecam");

		Global_Properties = properties;
		return properties;
	}

	void UpdateProperties(Game::Properties* properties)
	{
		Global_Properties = properties;
	}
}