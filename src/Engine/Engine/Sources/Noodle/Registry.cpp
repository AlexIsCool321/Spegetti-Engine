#include <Noodle/Registry.hpp>

#include <iostream>

namespace Noodle
{
	Registry::Registry()
	{
		this->m_entityRegister = std::map<std::string, std::function<Entity*()>>();
	}

	Registry::~Registry()
	{
		this->m_entityRegister.clear();
	}


	Entity* Registry::CreateEntity(std::string name)
	{
		std::function<Entity*()> CreateEntity = m_entityRegister[name.c_str()];
		if (!CreateEntity)
		{
			std::cout << "ERROR : Entity [ " << name << " ] not found in registry!" << std::endl;
			return nullptr;
		}

		Entity* entity = CreateEntity();
		entity->OnCreate();

		this->m_entities.push_back(entity);
		return entity;
	}


	void Registry::UpdateEntities()
	{
		for (unsigned int i = 0; i < this->m_entities.size(); i++)
		{
			if (this->m_entities[i] == nullptr)
			{
				this->m_entities.erase(this->m_entities.begin() + i);
				i--;
			}

			this->m_entities[i]->OnUpdate();
		}
	}

	void Registry::ClearEntities()
	{
		for (unsigned int i = 0; i < this->m_entities.size(); i++)
		{
			this->m_entities[i]->OnDestroy();
			delete this->m_entities[i];
		}

		this->m_entities.clear();
		this->m_entities.shrink_to_fit();
	}
}