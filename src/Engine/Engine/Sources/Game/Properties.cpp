#include <Game/Properties.hpp>

namespace Game
{
	Properties::Properties()
	{
		this->title = "";
		
		this->entityRegistry = new Noodle::Registry();
		this->renderServer = new Renderer::RenderServer();
	}


	Properties* mergeProperties(std::vector<Properties*> properties, std::string new_title)
	{
		Game::Properties* result = new Game::Properties();

		std::vector<Noodle::Registry*> registers;
		for (unsigned int i = 0; i < properties.size(); i++)
		{
			registers.push_back(properties[i]->entityRegistry);
		}

		result->entityRegistry = Noodle::mergeRegistries(registers);
		result->title = new_title;

		return result;
	}
}