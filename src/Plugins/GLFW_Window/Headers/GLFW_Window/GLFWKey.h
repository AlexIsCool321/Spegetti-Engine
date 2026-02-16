#ifndef GLFW_WINDOW_GLFWKEY_H
#define GLFW_WINDOW_GLFWKEY_H

#include <System/Key.h>

KEY GLFWtoKey(unsigned int pGlfwKey);
unsigned int KeytoGLFW(KEY pKey);

#endif