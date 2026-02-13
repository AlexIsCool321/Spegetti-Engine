#include <SDL_GL_Renderer/CreateContex.h>

#include <SDL_Window/SDL_IWindow.h>
#include <SDL3/SDL.h>

#include <stdio.h>

void PLUGIN_CreateContex(void** args)
{
	PLUGIN_SDL_Window* window;

	{
		if (!args[0]) printf("ERROR [PLUGIN] : WINDOW IS NULL!\n");

		if (!args[0]) return;

		window = (PLUGIN_SDL_Window*)args[0];
	}

	int num_drivers = SDL_GetNumRenderDrivers();   

	for (int i = 0; i < num_drivers; ++i)
	{
		const char* name = SDL_GetRenderDriver(i);
		printf("Renderer %d: %s\n", i, name);
	}

	if (!SDL_DestroyWindowSurface(window->m_SDLWindow))
	{
		printf("WARN : Failed to destroy window Surface. : [ %s ]\n", SDL_GetError());
	}

	SDL_DestroyRenderer(window->m_SDLRenderer);
	
	window->m_SDLRenderer = SDL_CreateRenderer(window->m_SDLWindow, "opengl");
	SDL_SetRenderVSync(window->m_SDLRenderer, 1);

	{
		if (!window->m_SDLRenderer)	printf("ERROR [PLUGIN] : FAILED TO CREATE SDL OPENGL RENDERER! : [ %s ]\n", SDL_GetError());

		if (!window->m_SDLRenderer) return;
	}
}

void PLUGIN_DestroyContex(void** args)
{
	PLUGIN_SDL_Window* window;

	{
		if (!args[0]) printf("ERROR [PLUGIN] : WINDOW IS NULL!\n");

		if (!args[0]) return;

		window = (PLUGIN_SDL_Window*)args[0];
	}
}