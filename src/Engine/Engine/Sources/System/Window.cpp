#include <System/Window.hpp>

#include <System/Specific/SDL3/SDL3_Window.hpp>

namespace System
{
	Window::Window()
	{

	}

	Window::~Window()
	{

	}


	void Window::Update()
	{
		
	}

	void Window::SwapBuffers()
	{

	}


	bool Window::IsOpen()
	{
		return false;
	}


	void Window::Rename(const char* title)
	{

	}

	const char* Window::GetName()
	{
		return "";
	}



	Window* CreateWindow(unsigned int width, unsigned int height, const char* title)
	{
		return static_cast<Window*>(new SDL3_Window(width, height, title));
	}
}