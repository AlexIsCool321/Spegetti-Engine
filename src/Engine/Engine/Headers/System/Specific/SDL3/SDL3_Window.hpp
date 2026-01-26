#ifndef SYSTEM_SDL3_WINDOW_HPP
#define SYSTEM_SDL3_WINDOW_HPP

#include <System/Window.hpp>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

namespace System
{
	class SDL3_Window : public Window
	{
	private:
		SDL_Window* m_window;
		bool m_running;

	public:
		SDL3_Window(unsigned int width, unsigned int height, const char* title);
		~SDL3_Window();

		void Update();
		void SwapBuffers();

		bool IsOpen();

		void Rename(const char* title);
		const char* GetName();
	};
}

#endif