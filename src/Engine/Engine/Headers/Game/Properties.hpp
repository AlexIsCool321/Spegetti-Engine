#ifndef PROPERTIES_HPP
#define PROPERTIES_HPP

#include <string>
#include <vector>

#include <Noodle/Noodle.hpp>

namespace Game
{
	struct Properties
	{
		std::string title;

		Noodle::Registry* entityRegistry;
	};

	Properties* mergeProperties(std::vector<Properties*> properties, std::string new_title);
}

#endif