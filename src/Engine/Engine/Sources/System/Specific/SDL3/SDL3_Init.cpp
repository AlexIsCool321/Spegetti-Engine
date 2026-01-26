#include <System/Specific/SDL3/SDL3_Init.hpp>

#include <Logging/Logging.hpp>

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

		Logging::Log("Initialized SDL3 Successfully!");
	}

	void SDL3_Terminate()
	{
		SDL_Quit();

		Logging::Log("Terminated SDL3 Successfully!");
	}
}