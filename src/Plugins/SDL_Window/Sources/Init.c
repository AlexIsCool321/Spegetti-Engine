#include <SDL_Window/Init.h>

#include <SDL3/SDL.h>

#include <stdio.h>

void PLUGIN_Init_System(void** args)
{
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "ERROR : FAILED TO INIT SDL3! : [ %s ]", SDL_GetError());
		return;
	}

	printf("Initialized SDL3 Successfully!\n");
}

void PLUGIN_Terminate_System(void** args)
{
	SDL_Quit();

	printf("Terminated SDL3 Successfully!\n");
}