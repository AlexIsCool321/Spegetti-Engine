#ifndef NOODLE_REGISTRY_HPP
#define NOODLE_REGISTRY_HPP

#include <Noodle/Entity.hpp>

#include <string>

#include <map>
#include <vector>
#include <functional>

namespace Noodle
{
	class Registry
	{
	private:
		std::map<std::string, std::function<Entity*()>> m_entityRegister;
		std::vector<Entity*> m_entities;

		friend Registry* mergeRegistries(std::vector<Registry*> registries);

	public:
		Registry();
		~Registry();

		template<typename T>
		void RegisterEntity(std::string type)
		{
			this->m_entityRegister[type] = std::function<Entity*()>([]() { return new T(); });
		}

		Entity* CreateEntity(std::string type, std::string name);

		void UpdateEntities();
		void ClearEntities();
	};

	Registry* mergeRegistries(std::vector<Registry*> registries);
}

#endif