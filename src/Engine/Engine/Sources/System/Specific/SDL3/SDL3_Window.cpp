#include <System/Specific/SDL3/SDL3_Window.hpp>

namespace System
{
	SDL3_Window::SDL3_Window(unsigned int width, unsigned int height, const char* title)
	{
		this->m_window = SDL_CreateWindow(title, width, height, SDL_WINDOW_RESIZABLE);
		if (!this->m_window)
		{
			SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_CreateWindow failed: %s", SDL_GetError());
			SDL_Quit();
			return;
		}

		SDL_ShowWindow(this->m_window);

		SDL_Surface* surface = SDL_GetWindowSurface(this->m_window);
		SDL_UpdateWindowSurface(this->m_window);

		this->m_running = true;
	}

	SDL3_Window::~SDL3_Window()
	{
		SDL_DestroyWindow(this->m_window);
		this->m_window = nullptr;

		this->m_running = false;
	}


	void SDL3_Window::Update()
	{
		SDL_Event event;
		SDL_zero(event);

		SDL_Surface* gScreenSurface = SDL_GetWindowSurface(this->m_window);

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT) this->m_running = false;
		}
	}

	void SDL3_Window::SwapBuffers()
	{
		SDL_UpdateWindowSurface(this->m_window);
	}


	bool SDL3_Window::IsOpen()
	{
		return this->m_running;
	}
}