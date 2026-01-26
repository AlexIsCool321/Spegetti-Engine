#include <Noodle/Registry.hpp>

#include <Logging/Logging.hpp>

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


	Entity* Registry::CreateEntity(std::string type, std::string name)
	{
		std::function<Entity*()> CreateEntity = m_entityRegister[type.c_str()];
		if (!CreateEntity)
		{
			Logging::Error("Entity [ %s ] not found in registry!", type);
			return nullptr;
		}

		Entity* entity = CreateEntity();
		entity->name = name;
		
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


	Registry* mergeRegistries(std::vector<Registry*> registers)
	{
		Registry* result = new Registry();
		
		for (unsigned int i = 0; i < registers.size(); i++)
		{
			result->m_entityRegister.merge(registers[i]->m_entityRegister);

			for (unsigned int j = 0; j < registers[i]->m_entities.size(); j++)
			{
				result->m_entities.push_back(registers[i]->m_entities[j]);
			}
		}

		return result;
	}
}