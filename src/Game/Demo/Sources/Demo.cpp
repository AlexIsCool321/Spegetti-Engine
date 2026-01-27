#include <Demo/Demo.hpp>

#include <Demo/Freecam.hpp>

namespace Demo
{
	Game::Properties* Global_Properties = nullptr;
}

Game::Properties* Init()
{
	Demo::Global_Properties = new Game::Properties();
		
	Demo::Global_Properties->title = "Demo";

	Demo::Global_Properties->entityRegistry = new Noodle::Registry();
	Demo::Global_Properties->entityRegistry->RegisterEntity<Demo::Freecam>("Freecam");

	return Demo::Global_Properties;
} 