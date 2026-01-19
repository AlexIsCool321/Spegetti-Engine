#ifndef PROPERTIES_HPP
#define PROPERTIES_HPP

#include <string>

#include <Noodle/Noodle.hpp>

namespace Game
{
	struct Properties
	{
		std::string title;

		Noodle::Registry* registry;
	};
}

#endif