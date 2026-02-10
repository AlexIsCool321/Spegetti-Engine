#ifndef SDL_IWINDOW_H
#define SDL_IWINDOW_H

#include <System/IWindow.h>

#include <SDL3/SDL.h>

typedef struct
{
	IWindow base;
	SDL_Window* m_SDLWindow;
} PLUGIN_SDL_Window;

IWindow* PLUGIN_CreateWindow(void** args);

void PLUGIN_UpdateWindow(void** args);

void PLUGIN_DestroyWindow(void** args);

#endif