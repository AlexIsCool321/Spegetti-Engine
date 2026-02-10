#include <SDL_Window/SDL_IWindow.h>

#include <SDL3/SDL_main.h>

#include <stdio.h>
#include <stdlib.h>

IWindow* PLUGIN_CreateWindow(void** args)
{
	unsigned int width = *(unsigned int*)args[0];
	unsigned int height = *(unsigned int*)args[1];
	const char* title = *(const char**)args[2];

	PLUGIN_SDL_Window* result = (PLUGIN_SDL_Window*)malloc(sizeof(PLUGIN_SDL_Window));
	result->base.m_open = 1;

	result->m_SDLWindow = SDL_CreateWindow(title, width, height, SDL_WINDOW_RESIZABLE);
	if (!result->m_SDLWindow)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "ERROR : FAILED TO CREATE SDL WINDO! : [ %s ]", SDL_GetError());
		SDL_Quit();
		return NULL;
	}

	SDL_ShowWindow(result->m_SDLWindow);

	SDL_Surface* surface = SDL_GetWindowSurface(result->m_SDLWindow);
	SDL_UpdateWindowSurface(result->m_SDLWindow);

	return (IWindow*)result;
}


void PLUGIN_UpdateWindow(void** args)
{
	PLUGIN_SDL_Window* window = (PLUGIN_SDL_Window*)args[0];
	if (!window)
	{
		printf("ERROR : WINDOW IS NULL!");
		return;
	}

	SDL_Event event;
	SDL_zero(event);

	SDL_Surface* gScreenSurface = SDL_GetWindowSurface(window->m_SDLWindow);

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_EVENT_QUIT:
			{
				window->base.m_open = 0;
			}
			case SDL_EVENT_WINDOW_RESIZED:
			{
				SDL_Surface* surface = SDL_GetWindowSurface(window->m_SDLWindow);
		        SDL_UpdateWindowSurface(window->m_SDLWindow);
			}
		}
	}
}


void PLUGIN_DestroyWindow(void** args)
{
	PLUGIN_SDL_Window* window = (PLUGIN_SDL_Window*)args[0];
	if (!window)
	{
		printf("ERROR : WINDOW IS NULL!");
		return;
	}

	SDL_DestroyWindow(window->m_SDLWindow);
	window->m_SDLWindow = NULL;

	window->base.m_open = 0;
}