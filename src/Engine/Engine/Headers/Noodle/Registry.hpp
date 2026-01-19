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

	public:
		Registry();
		~Registry();

		template<typename T>
		void RegisterEntity(std::string name)
		{
			m_entityRegister[name] = std::function<Entity*()>([]() { return new T(); });
		}

		Entity* CreateEntity(std::string name);

		void UpdateEntities();
		void ClearEntities();
	};
}

#endif