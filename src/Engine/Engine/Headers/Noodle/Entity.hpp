#ifndef NOODLE_ENTITY_HPP
#define NOODLE_ENTITY_HPP

#include <string>

namespace Noodle
{
	class Entity
	{
	public:
		std::string name;

		Entity() = default;
		virtual ~Entity() = default;

		virtual void OnCreate();
		virtual void OnUpdate();
		virtual void OnDestroy();
	};
}

#endif