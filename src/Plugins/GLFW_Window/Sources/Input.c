#include <GLFW_Window/Input.h>

#include <GLFW_Window/GLFW_Window.h>
#include <GLFW_Window/GLFWKey.h>

#include <stdio.h>
#include <stdlib.h>

Vec2* MousePosition;
Vec2* MouseMotion;

void SetupMouseInput(GLFWwindow* pWindow)
{
	MousePosition	= (Vec2*)malloc(sizeof(Vec2));
	MouseMotion		= (Vec2*)malloc(sizeof(Vec2));
}

void UpdateMouseInput(GLFWwindow* pWindow)
{
	static double oldX = 0;
	static double oldY = 0;

	double X;
	double Y;
	glfwGetCursorPos(pWindow, &X, &Y);

	*MousePosition = Vector2(X, Y);

	*MouseMotion = Vector2(oldX - X, oldY - Y);

	oldX = MousePosition->x;
	oldY = MousePosition->y;
}



void* PLUGIN_IsKeyPressed(void** pArgs)
{
	KEY pKey;
	GLFW_Window* window = (GLFW_Window*)GetCurrentWindow();
	if (!window) return NULL;

	{
		if (!pArgs[0]) printf("ERROR [PLUGIN] : KEY IS NULL!\n");

		if (!pArgs[0]) return 0;

		pKey	= *(KEY*)pArgs[0];
	}

	uint8_t* result = (uint8_t*)malloc(sizeof(uint8_t));
	*result = glfwGetKey(window->m_window, KeytoGLFW(pKey)) == GLFW_PRESS;
	
	return (void*)result;
}


void* PLUGIN_GetMouseMotion(void** pArgs)
{
	return (void*)MouseMotion;
}

void* PLUGIN_GetMousePosition(void** pArgs)
{
	return (void*)MousePosition;
}