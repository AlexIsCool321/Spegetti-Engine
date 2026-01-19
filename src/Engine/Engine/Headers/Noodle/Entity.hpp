#ifndef NOODLE_ENTITY_HPP
#define NOODLE_ENTITY_HPP

namespace Noodle
{
	class Entity
	{
	public:
		Entity() = default;
		virtual ~Entity() = default;

		virtual void OnCreate();
		virtual void OnUpdate();
		virtual void OnDestroy();
	};
}

#endif