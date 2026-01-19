#include <iostream>

#include <Launcher/LoadGame.hpp>

int main()
{
	Game::Properties* properties = Launcher::LoadGame("Demo");

	Noodle::Entity* Freecam = properties->registry->CreateEntity("Freecam");
	
	Freecam->OnCreate();
	while (true)
	{
		Freecam->OnUpdate();
	}

	Freecam->OnDestroy();

	return 0;
}