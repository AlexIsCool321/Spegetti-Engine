#ifndef GLFW_SYSTEM_INPUT_H
#define GLFW_SYSTEM_INPUT_H

#include <System/Input.h>

void* PLUGIN_IsKeyPressed(void** pArgs);

void* PLUGIN_GetMouseMotion(void** pArgs);
void* PLUGIN_GetMousePosition(void** pArgs);

#endif