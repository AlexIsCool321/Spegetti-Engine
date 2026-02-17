#include <GLFW_Window/Input.h>

#include <GLFW_Window/GLFW_Window.h>
#include <GLFW_Window/GLFWKey.h>

#include <stdio.h>

void* PLUGIN_IsKeyPressed(void** pArgs)
{
	GLFW_Window* pWindow;
	KEY pKey;
	
	{
		if (!pArgs[0]) printf("ERROR [PLUGIN] : WINDOW IS NULL!\n");
		if (!pArgs[1]) printf("ERROR [PLUGIN] : KEY IS NULL!\n");

		if (!pArgs[0] || !pArgs[1]) return 0;

		pWindow	= (GLFW_Window*)pArgs[0];
		pKey	= *(KEY*)pArgs[1];
	}

	unsigned int glfwKey = KeytoGLFW(pKey);

	uint8_t pressed = glfwGetKey(pWindow->m_window, glfwKey) == GLFW_PRESS;
	
	return (void*)(intptr_t)pressed;
}


void* PLUGIN_GetMouseMotion(void** pArgs)
{
	static double oldX = 0;
	static double oldY = 0;
	
	GLFW_Window* pWindow;
	
	{
		if (!pArgs[0]) printf("ERROR [PLUGIN] : WINDOW IS NULL!\n");

		if (!pArgs[0]) return 0;

		pWindow	= (GLFW_Window*)pArgs[0];
	}

	double x;
	double y;
	glfwGetCursorPos(pWindow->m_window, &x, &y);

	Vec2 position = Vector2(oldX - x, oldY - y);

	oldX = x;
	oldY = y;

	intptr_t result = (intptr_t)&position;
	return (void*)result;
}

void* PLUGIN_GetMousePosition(void** pArgs)
{
	GLFW_Window* pWindow;
	
	{
		if (!pArgs[0]) printf("ERROR [PLUGIN] : WINDOW IS NULL!\n");

		if (!pArgs[0]) return 0;

		pWindow	= (GLFW_Window*)pArgs[0];
	}

	double x;
	double y;
	glfwGetCursorPos(pWindow->m_window, &x, &y);

	Vec2 position = Vector2(x, y);

	intptr_t result = (intptr_t)&position;

	return (void*)result;
}