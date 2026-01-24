#include <iostream>

#include <Launcher/LoadGame.hpp>
#include <vector>

int main()
{
	std::vector<Game::Properties*> game_properties;

	game_properties.push_back(Launcher::LoadGame("Engine"));
	game_properties.push_back(Launcher::LoadGame("Demo"));

	Game::Properties* properties = Game::mergeProperties(game_properties, "Demo");

	Noodle::Entity* Freecam = properties->entityRegistry->CreateEntity("Freecam", "freecam");
	Noodle::Entity* Model = properties->entityRegistry->CreateEntity("Model", "cube");

	while (true)
	{
		properties->entityRegistry->UpdateEntities();
	}

	properties->entityRegistry->ClearEntities();

	return 0;
}