#include <iostream>

#include <Launcher/LoadGame.hpp>

int main()
{
	Game::Properties* properties = Launcher::LoadGame("Demo");

	return 0;
}