#ifndef SYSTEM_WINDOW_HPP
#define SYSTEM_WINDOW_HPP

namespace System
{
	class Window
	{
	public:
		Window();
		~Window();

		virtual void Update();
		virtual void SwapBuffers();

		virtual bool IsOpen();
	};

	Window* CreateWindow(unsigned int width, unsigned int height, const char* title);
}

#endif