#include <GLFW_Window/GLFW_Window.h>

#include <stdio.h>
#include <stdlib.h>

void* PLUGIN_CreateWindow(void** args)
{
	unsigned int width;
	unsigned int height;
	const char* title;

	{
		if (!args[0]) printf("ERROR [PLUGIN] : WIDTH IS NULL!\n");
		if (!args[1]) printf("ERROR [PLUGIN] : HEIGHT IS NULL!\n");
		if (!args[2]) printf("ERROR [PLUGIN] : TITLE IS NULL!\n");

		if (!args[0] || !args[1] || !args[2]) return NULL;

		width	= *(unsigned int*)	args[0];
		height	= *(unsigned int*)	args[1];
		title	= *(const char**)	args[2];
	}


	GLFW_Window* result = (GLFW_Window*)malloc(sizeof(GLFW_Window));
	if (!result)
	{
		printf("ERROR [PLUGIN] : FAILED TO ALLOCATE MEMORY FOR WINDOW!\n");
		return NULL;
	}

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	result->m_window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!result->m_window)
	{
		printf("ERROR [PLUGIN] : FAILED TO CREATE GLFW WINDO!\n");
		return NULL;
	}

	return (IWindow*)result;
}


void PLUGIN_UpdateWindow(void** args)
{
	GLFW_Window* window;
	
	{
		if (!args[0]) printf("ERROR [PLUGIN] : WINDOW IS NULL!\n");

		if (!args[0]) return;

		window = (GLFW_Window*)args[0];
	}

	glfwSwapBuffers(window->m_window);
    glfwPollEvents();
}

void* PLUGIN_IsWindowOpen(void** args)
{
	GLFW_Window* window;
	
	{
		if (!args[0]) printf("ERROR [PLUGIN] : WINDOW IS NULL!\n");

		if (!args[0]) return 0;

		window = (GLFW_Window*)args[0];
	}

	uint8_t open = !glfwWindowShouldClose(window->m_window);
	return (void*)(intptr_t)open;
}


void PLUGIN_DestroyWindow(void** args)
{
	GLFW_Window* window;
	
	{
		if (!args[0]) printf("ERROR [PLUGIN] : WINDOW IS NULL!\n");

		if (!args[0]) return;

		window = (GLFW_Window*)args[0];
	}

	glfwDestroyWindow(window->m_window);

	free(window);

	args[0] = NULL;
}