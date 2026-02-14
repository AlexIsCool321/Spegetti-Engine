#include <GL_GLFW/Contex.h>

//#include <GLFW_Window/GLFW_Window.h>

#include <GLFW/glfw3.h>

#include <stdio.h>

void PLUGIN_CreateWindowContex(void** args)
{
	/*
	GLFW_Window* window;
	
	{
		if (!args[0]) printf("ERROR [PLUGIN] : WINDOW IS NULL!\n");

		if (!args[0]) return;

		window = (GLFW_Window*)args[0];
	}

	const char* title = glfwGetWindowTitle(window->m_window);

	int width;
	int height;
	glfwGetWindowSize(window->m_window, &width, &height);

	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
	GLFWwindow* GLWindow = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwMakeContextCurrent(GLWindow);

	glfwDestroyWindow(window->m_window);
	window->m_window = GLWindow;
	*/
}