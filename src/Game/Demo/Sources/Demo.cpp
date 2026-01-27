#include <Demo/Demo.hpp>

#include <Demo/Freecam.hpp>

Game::Properties* Global_Properties = nullptr;

Game::Properties* Init()
{
	Global_Properties = new Game::Properties();
		
	Global_Properties->title = "Demo";

	Global_Properties->entityRegistry = new Noodle::Registry();
	Global_Properties->entityRegistry->RegisterEntity<Demo::Freecam>("Freecam");

	return Global_Properties;
} 