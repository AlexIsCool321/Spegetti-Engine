#include <iostream>

#include <Launcher/LoadGame.hpp>

int main()
{
	Game::Properties* properties = Launcher::LoadGame("Demo");

	Noodle::Entity* Freecam = properties->registry->CreateEntity("Freecam");

	while (true)
	{
		properties->registry->UpdateEntities();
	}

	properties->registry->ClearEntities();

	return 0;
}