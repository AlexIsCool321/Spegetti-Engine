#include <GLFW_Window/Init.h>

#include <GLFW/glfw3.h>

#include <stdio.h>

void PLUGIN_InitSystem(void** args)
{
	if (!glfwInit())
	{
		const char* errorLog;
		glfwGetError(&errorLog);

		printf("ERROR [PLUGIN] : FAILED TO INITIALIZE GLFW! : [ %s ]\n", errorLog);

		glfwTerminate();
		return;
	}

	printf("LOG [PLUGIN] : Initialized GLFW Successfully!\n");
}

void PLUGIN_TerminateSystem(void** args)
{
	glfwTerminate();

	printf("LOG [PLUGIN] : Terminated GLFW Successfully!\n");
}