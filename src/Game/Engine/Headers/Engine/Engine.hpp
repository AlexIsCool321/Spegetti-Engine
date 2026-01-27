#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <Game/Game.hpp>
using namespace Game;

#include <Engine/Model.hpp>

extern "C"
{
	Properties* Global_Properties;

	Properties* Init();
	void UpdateProperties(Properties* properties);
}

#endif