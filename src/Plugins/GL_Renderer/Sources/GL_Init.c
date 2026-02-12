#include <GL_Renderer/GL_Init.h>
#include <Renderer/LoadProcAddress.h>

#include <stdio.h>

#include <glad/gl.h>

void PLUGIN_InitRenderer(void** args)
{
	LoadProcAddress* loadProcAddress;

	{
		if (!args)
		{
			printf("ERROR : ARGUMENTS IS NULL!\n");
			return;
		}

		if (!args[0]) printf("ERROR : LOAD PROCEDURE ADDRESS IS NULL!\n");

		if (!args[0]) return;

		loadProcAddress = (LoadProcAddress*)args[0];
	}

	int version = gladLoadGL(loadProcAddress->m_address);
	if (version == 0)
	{
		printf("ERROR : FAILED TO LOAD OPENGL!\n");
		return;
	}

	printf("LOG : Initialized OpenGL Successfully!\n");
}

void PLUGIN_TerminateRenderer(void** args)
{
	gladLoaderUnloadGL();

	printf("LOG : Terminated OpenGL Successfully!\n");
}
