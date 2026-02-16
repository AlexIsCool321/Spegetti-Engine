#include <MGL_Renderer/Init.h>

#include <glad/gl.h>

#include <stdio.h>

void PLUGIN_InitRenderer(void** pArgs)
{
	GLADloadfunc address;

	{
		if (!pArgs[0]) printf("ERROR [PLUGIN] : PROCEDURE ADDRESS IS NULL!\n");

		if (!pArgs[0]) return;

		address = (GLADloadfunc)pArgs[0];
	}

	int version = gladLoadGL(address);
	if (version == 0)
	{
		printf("ERROR [PLUGIN] : FAILED TO INITIALIZE OPENGL!\n");
		printf("LOG [PLUGIN] : Have you created a Window?\n");
		
		return;
	}

	printf("Initialized OpenGL Successfully!\n");
}

void PLUGIN_TerminateRenderer(void** pArgs)
{
	printf("Terminated OpenGL Successfully!\n");
}