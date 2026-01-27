#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <Core/Core.hpp>
using namespace Game;
using namespace Logging;
using namespace Noodle;
using namespace Renderer;
using namespace System;

#include <Engine/Global_Properties.hpp>

extern "C"
{
	Properties* Init();
}

#endif