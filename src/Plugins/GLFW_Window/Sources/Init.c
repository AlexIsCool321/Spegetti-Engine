#include <GLFW_Window/Init.h>

#include <GLFW/glfw3.h>

#include <stdio.h>

void PLUGIN_InitSystem(void** args)
{
	// Hopefully Temparary
	glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);

	if (!glfwInit())
	{
		const char* errorLog;
		glfwGetError(&errorLog);

		printf("ERROR [PLUGIN] : FAILED TO INITIALIZE GLFW! : [ %s ]\n", errorLog);

		glfwTerminate();
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	printf("LOG [PLUGIN] : Initialized GLFW Successfully!\n");
}

void PLUGIN_TerminateSystem(void** args)
{
	glfwTerminate();

	printf("LOG [PLUGIN] : Terminated GLFW Successfully!\n");
}