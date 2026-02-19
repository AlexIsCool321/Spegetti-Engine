#ifndef GLFW_SYSTEM_INPUT_H
#define GLFW_SYSTEM_INPUT_H

#include <System/Input.h>

#include <GLFW/glfw3.h>

void UpdateMouse(GLFWwindow* pWindow);

void* PLUGIN_IsKeyPressed(void** pArgs);

void* PLUGIN_GetMouseMotion(void** pArgs);
void* PLUGIN_GetMousePosition(void** pArgs);

#endif