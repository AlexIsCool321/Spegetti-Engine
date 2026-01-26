#include <Game/Properties.hpp>

namespace Game
{
	Properties::Properties()
	{
		this->title = "";
		
		this->entityRegistry = new Noodle::Registry();
		this->renderServer = new Renderer::RenderServer();
	}


	Properties* mergeProperties(std::vector<Properties*>& properties, std::string new_title)
	{
		Game::Properties* result = new Game::Properties();

		std::vector<Noodle::Registry*> registers;
		for (Properties* property : properties)
		{
			registers.push_back(property->entityRegistry);
		}

		result->entityRegistry = Noodle::mergeRegistries(registers);
		result->title = new_title;

		for (Properties* property : properties)
		{
			delete property;
		}

		return result;
	}
}