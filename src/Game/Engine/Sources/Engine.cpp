#include <Engine/Engine.hpp>

#include <Engine/Model.hpp>

namespace Engine
{
	Game::Properties* Global_Properties = nullptr;
}

Properties* Init()
{
	Engine::Global_Properties = new Properties();
		
	Engine::Global_Properties->title = "Engine";

	Engine::Global_Properties->entityRegistry->RegisterEntity<Engine::Model>("Model");

	return Engine::Global_Properties;
}