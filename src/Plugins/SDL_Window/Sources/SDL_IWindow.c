#include <SDL_Window/SDL_IWindow.h>

#include <SDL3/SDL_main.h>

#include <stdio.h>
#include <stdlib.h>

IWindow* PLUGIN_CreateWindow(void** args)
{
	unsigned int width;
	unsigned int height;
	const char* title;

	{
		if (!args[0]) printf("ERROR [PLUGIN] : WIDTH IS NULL!\n");
		if (!args[1]) printf("ERROR [PLUGIN] : HIEGHT IS NULL!\n");
		if (!args[2]) printf("ERROR [PLUGIN] : TITLE IS NULL!\n");

		if (!args[0] || !args[1] || !args[2]) return NULL;

		width	=	*(unsigned int*)	args[0];
		height	=	*(unsigned int*)	args[1];
		title	=	*(const char**)		args[2];
	}

	PLUGIN_SDL_Window* result = (PLUGIN_SDL_Window*)malloc(sizeof(PLUGIN_SDL_Window));
	result->base.m_open = 1;

	result->m_SDLWindow = SDL_CreateWindow(title, width, height, SDL_WINDOW_RESIZABLE);
	if (!result->m_SDLWindow)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "ERROR [PLUGIN] : FAILED TO CREATE SDL WINDOW! : [ %s ]", SDL_GetError());
		SDL_Quit();
		return NULL;
	}

	result->m_Context = SDL_GL_CreateContext(result->m_SDLWindow);

	SDL_ShowWindow(result->m_SDLWindow);

	SDL_Surface* surface = SDL_GetWindowSurface(result->m_SDLWindow);
	SDL_UpdateWindowSurface(result->m_SDLWindow);

	return (IWindow*)result;
}


LoadProcAddress* PLUGIN_GetWindowLoadProcAddress(void** args)
{
	PLUGIN_SDL_Window* window;

	{
		if (!args[0]) printf("ERROR [PLUGIN] : WINDOW IS NULL!\n");

		if (!args[0]) return NULL;

		window = (PLUGIN_SDL_Window*)args[0];
	}

	LoadProcAddress* result = CreateAddress(SDL_GL_GetProcAddress);

	return result;
}


void PLUGIN_UpdateWindow(void** args)
{
	PLUGIN_SDL_Window* window;

	{
		if (!args[0]) printf("ERROR [PLUGIN] : WINDOW IS NULL!\n");

		if (!args[0]) return;

		window = (PLUGIN_SDL_Window*)args[0];
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

void PLUGIN_SwapWindowBuffers(void** args)
{
	PLUGIN_SDL_Window* window;

	{
		if (!args[0]) printf("ERROR [PLUGIN] : WINDOW IS NULL!\n");

		if (!args[0]) return;

		window = (PLUGIN_SDL_Window*)args[0];
	}

	SDL_UpdateWindowSurface(window->m_SDLWindow);
}


void PLUGIN_DestroyWindow(void** args)
{
	PLUGIN_SDL_Window* window;

	{
		if (!args[0]) printf("WARN [PLUGIN] : Window is already NULL.\n");

		if (!args[0]) return;

		window = (PLUGIN_SDL_Window*)args[0];
	}

	SDL_GL_DestroyContext(window->m_Context);
	window->m_Context = NULL;

	SDL_DestroyWindow(window->m_SDLWindow);
	window->m_SDLWindow = NULL;

	window->base.m_open = 0;
}