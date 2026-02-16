#include <GLFW_Window/GLFW_Window.h>

#include <Renderer/Surface.h>
#include <Renderer/Instance.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

void PLUGIN_AttachSurfaceAndInstanceToWindow(void** pArgs)
{
	GLFW_Window* window;
	Surface* surface;
	Instance* instance;
	
	{
		// Don't check if Surface is NULL, because it will be assumed to be OpenGL if it is NULL.
		if (!pArgs[0]) printf("ERROR [PLUGIN] : WINDOW IS NULL!\n");

		if (!pArgs[0]) return;

		window		= (GLFW_Window*)pArgs[0];
		surface		= (Surface*)pArgs[1];
		instance	= (Instance*)pArgs[2];
	}

	if (!surface || !instance)
	{
		const char* title = glfwGetWindowTitle(window->m_window);
		
		int width;
		int height;
		glfwGetWindowSize(window->m_window, &width, &height);

		glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
		GLFWwindow* GLWindow = glfwCreateWindow(width, height, title, NULL, NULL);
		
		glfwDestroyWindow(window->m_window);
		window->m_window = GLWindow;

		glfwMakeContextCurrent(window->m_window);
	}
	else
	{
#ifdef VK_VERSION_1_0
		glfwCreateWindowSurface(instance, window->m_window, NULL, &surface);
#endif
	}
}