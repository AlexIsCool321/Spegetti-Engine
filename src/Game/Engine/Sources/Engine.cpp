#include <Engine/Engine.hpp>

#include <Engine/Model.hpp>

Game::Properties* Global_Properties = nullptr;

Properties* Init()
{
	Global_Properties = new Properties();
		
	Global_Properties->title = "Engine";

	Global_Properties->entityRegistry->RegisterEntity<Engine::Model>("Model");

	return Global_Properties;
}