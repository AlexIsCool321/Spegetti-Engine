#ifndef MODEL_HPP
#define MODEL_HPP

#include <Noodle/Noodle.hpp>

namespace Engine
{
	class Model : public Noodle::Entity
	{
	public:
		void OnCreate();
		void OnUpdate();
		void OnDestroy();
	};
}

#endif