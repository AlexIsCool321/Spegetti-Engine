#ifndef DEMO_HPP
#define DEMO_HPP

#include <Game/Game.hpp>
using namespace Game;

#include <Demo/Freecam.hpp>

extern "C"
{
	Properties* Global_Properties;

	Properties* Init();
	void UpdateProperties(Properties* properties);
}
#endif