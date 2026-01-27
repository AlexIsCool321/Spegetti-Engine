#include <iostream>
#include <vector>

#include <Core/Core.hpp>

#include <Launcher/Launcher.hpp>
using namespace Launcher;

int main()
{
	System::Init();

	System::Window* window = System::CreateWindow(800, 600, "Game");


	// Load Game
	GameClient* engine = CreateGameClient("Engine");
	GameClient* client = CreateGameClient("Demo");

	std::vector<Game::Properties*> game_properties;

	game_properties.push_back(engine->GetPropreties());
	game_properties.push_back(client->GetPropreties());

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

	delete properties;

	delete engine;
	delete client;

	return 0;
}