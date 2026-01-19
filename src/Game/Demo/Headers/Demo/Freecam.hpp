#ifndef Freecam_hpp
#define Freecam_hpp

#include <Noodle/Noodle.hpp>

namespace Demo
{
	class Freecam : public Noodle::Entity
	{
	public:
		void OnCreate();
		void OnUpdate();
		void OnDestroy();
	};
}

#endif