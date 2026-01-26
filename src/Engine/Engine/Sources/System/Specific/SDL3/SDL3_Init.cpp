#include <System/Specific/SDL3/SDL3_Init.hpp>

#include <iostream>

#include <SDL3/SDL.h>

namespace System
{
	void SDL3_Init()
	{
		if (!SDL_Init(SDL_INIT_VIDEO))
		{
			SDL_LogError(SDL_LOG_CATEGORY_ERROR, "ERROR : FAILED TO INIT SDL3! : [ %s ]", SDL_GetError());
			return;
		}

		std::cout << "LOG : SDL3 Initialized Successfully!" << std::endl;
	}

	void SDL3_Terminate()
	{
		SDL_Quit();

		std::cout << "LOG : SDL3 Terminated Successfully!" << std::endl;
	}
}