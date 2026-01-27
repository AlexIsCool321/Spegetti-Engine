#ifndef FREECAM_HPP
#define FREECAM_HPP

#include <Demo/Demo.hpp>

namespace Demo
{
	class Freecam : public Entity
	{
	public:
		void OnCreate();
		void OnUpdate();
		void OnDestroy();
	};
}

#endif