#ifndef PROPERTIES_HPP
#define PROPERTIES_HPP

#include <string>
#include <vector>

#include <Noodle/Noodle.hpp>
#include <Renderer/Renderer.hpp>

namespace Game
{
	struct Properties
	{
		Properties();

		std::string title;

		Noodle::Registry* entityRegistry;
		Renderer::RenderServer* renderServer;
	};

	Properties* mergeProperties(std::vector<Properties*> properties, std::string new_title);
}

#endif