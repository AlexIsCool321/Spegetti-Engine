#include <GLFW_Window/Input.h>

#include <GLFW_Window/GLFW_Window.h>
#include <GLFW_Window/GLFWKey.h>

#include <stdio.h>

Vec2 MousePosition;
Vec2 MouseMotion;

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
	intptr_t result = (intptr_t)&MouseMotion;
	return (void*)result;
}

void* PLUGIN_GetMousePosition(void** pArgs)
{
	intptr_t result = (intptr_t)&MousePosition;
	return (void*)result;
}

void UpdateMouse(GLFWwindow* pWindow)
{
	static double oldX = 0;
	static double oldY = 0;

	double X;
	double Y;
	glfwGetCursorPos(pWindow, &X, &Y);

	MousePosition = Vector2(X, Y);

	MouseMotion = Vector2(oldX - X, oldY - Y);

	oldX = MousePosition.x;
	oldY = MousePosition.y;
}