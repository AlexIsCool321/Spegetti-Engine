#ifndef GLFW_WINDOW_WINDOW_H
#define GLFW_WINDOW_WINDOW_H

#include <System/IWindow.h>

#include <GLFW/glfw3.h>

typedef struct
{
	GLFWwindow* m_window;
} GLFW_Window;

void* PLUGIN_CreateWindow(void** pArgs);

void PLUGIN_UpdateWindow(void** pArgs);
void* PLUGIN_IsWindowOpen(void** pArgs);

void* PLUGIN_GetWindowProcedureAddress(void** pArgs);

void PLUGIN_DestroyWindow(void** pArgs);

#endif