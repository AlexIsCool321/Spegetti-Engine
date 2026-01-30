#include <Engine/Engine.hpp>

#include <Engine/Model.hpp>

namespace Engine
{
	Game::Properties* Global_Properties = nullptr;
}

Properties* Init()
{
	Engine::Global_Properties = new Game::Properties();
	
	Engine::Global_Properties->title = "Engine";

	Engine::Global_Properties->renderServer = Renderer::createRenderServer(Renderer::API_TYPE::OPENGL);
	Engine::Global_Properties->entityRegistry = new Noodle::Registry();

	Engine::Global_Properties->entityRegistry->RegisterEntity<Engine::Model>("Model");

	return Engine::Global_Properties;
}