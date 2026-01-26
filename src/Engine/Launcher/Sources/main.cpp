#include <iostream>

#include <Launcher/LoadGame.hpp>
#include <vector>

#include <System/System.hpp>

int main()
{
	System::Init();

	System::Window* window = System::CreateWindow(800, 600, "Game");


	// Load Game
	std::vector<Game::Properties*> game_properties;

	game_properties.push_back(Launcher::LoadGame("Engine"));
	game_properties.push_back(Launcher::LoadGame("Demo"));

	Game::Properties* properties = Game::mergeProperties(game_properties, "Demo");

	
	window->Rename(properties->title.c_str());
	properties->renderServer->AssignWindow(window);


	Noodle::Entity* Freecam = properties->entityRegistry->CreateEntity("Freecam", "freecam");
	Noodle::Entity* Model = properties->entityRegistry->CreateEntity("Model", "cube");

	while (window->IsOpen())
	{
		window->Update();

		properties->entityRegistry->UpdateEntities();

		window->SwapBuffers();
	}

	delete window;

	System::Terminate();

	properties->entityRegistry->ClearEntities();

	return 0;
}