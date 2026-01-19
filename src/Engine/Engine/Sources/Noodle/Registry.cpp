#include <Noodle/Registry.hpp>

#include <iostream>

namespace Noodle
{
	Registry::Registry()
	{
		this->m_entities = std::map<std::string, std::function<Entity*()>>();
	}

	Registry::~Registry()
	{
		this->m_entities.clear();
	}


	Entity* Registry::CreateEntity(std::string name)
	{
		std::function<Entity*()> CreateEntity = m_entities[name.c_str()];
		if (!CreateEntity)
		{
			std::cout << "ERROR : Entity [ " << name << " ] not found in registry!" << std::endl;
			return nullptr;
		}

		Entity* entity = CreateEntity();
		
		return entity;
	}
}