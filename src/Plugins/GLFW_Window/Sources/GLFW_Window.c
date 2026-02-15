#include <GLFW_Window/GLFW_Window.h>

#include <stdio.h>
#include <stdlib.h>

void* PLUGIN_CreateWindow(void** pArgs)
{
	unsigned int width;
	unsigned int height;
	const char* title;

	{
		if (!pArgs[0]) printf("ERROR [PLUGIN] : WIDTH IS NULL!\n");
		if (!pArgs[1]) printf("ERROR [PLUGIN] : HEIGHT IS NULL!\n");
		if (!pArgs[2]) printf("ERROR [PLUGIN] : TITLE IS NULL!\n");

		if (!pArgs[0] || !pArgs[1] || !pArgs[2]) return NULL;

		width	= *(unsigned int*)	pArgs[0];
		height	= *(unsigned int*)	pArgs[1];
		title	= *(const char**)	pArgs[2];
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
	glfwMakeContextCurrent(result->m_window);

	return (IWindow*)result;
}


void PLUGIN_UpdateWindow(void** pArgs)
{
	GLFW_Window* window;
	
	{
		if (!pArgs[0]) printf("ERROR [PLUGIN] : WINDOW IS NULL!\n");

		if (!pArgs[0]) return;

		window = (GLFW_Window*)pArgs[0];
	}

	glfwPollEvents();
}

void PLUGIN_SwapWindowBuffers(void** pArgs)
{
	GLFW_Window* window;
	
	{
		if (!pArgs[0]) printf("ERROR [PLUGIN] : WINDOW IS NULL!\n");

		if (!pArgs[0]) return;

		window = (GLFW_Window*)pArgs[0];
	}

	glfwSwapBuffers(window->m_window);
}


void* PLUGIN_IsWindowOpen(void** pArgs)
{
	GLFW_Window* window;
	
	{
		if (!pArgs[0]) printf("ERROR [PLUGIN] : WINDOW IS NULL!\n");

		if (!pArgs[0]) return 0;

		window = (GLFW_Window*)pArgs[0];
	}

	uint8_t open = !glfwWindowShouldClose(window->m_window);
	return (void*)(intptr_t)open;
}


void* PLUGIN_GetWindowProcedureAddress(void** pArgs)
{
	return (void*)glfwGetProcAddress;
}


void PLUGIN_DestroyWindow(void** pArgs)
{
	GLFW_Window* window;
	
	{
		if (!pArgs[0]) printf("WARN [PLUGIN] : Window is already NULL.\n");

		if (!pArgs[0]) return;

		window = (GLFW_Window*)pArgs[0];
	}

	glfwDestroyWindow(window->m_window);

	free(window);

	pArgs[0] = NULL;
}