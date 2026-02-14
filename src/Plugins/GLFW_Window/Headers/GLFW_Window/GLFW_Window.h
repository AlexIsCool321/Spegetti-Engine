#ifndef GLFW_WINDOW_H
#define GLFW_WINDOW_H

#include <System/IWindow.h>

#include <GLFW/glfw3.h>

typedef struct
{
	GLFWwindow* m_window;
} GLFW_Window;

void* PLUGIN_CreateWindow(void** args);

void PLUGIN_UpdateWindow(void** args);
void* PLUGIN_IsWindowOpen(void** args);

void PLUGIN_DestroyWindow(void** args);

#endif