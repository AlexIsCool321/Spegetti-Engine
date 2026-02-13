#include <SDL_GL_Renderer/Init.h>

#include <SDL3/SDL.h>
#include <glad/gl.h>

#include <stdio.h>

void PLUGIN_InitRenderer(void** args)
{
	int version = gladLoadGL(SDL_GL_GetProcAddress);
	if (version == 0)
	{
		printf("ERROR [PLUGIN] : FAILED TO INIT OPENGL!\n");
		return;
	}

	printf("LOG [PLUGIN] : Loaded GLAD2 Successfully!\n");
}

void PLUGIN_TerminateRenderer(void** args)
{
	printf("LOG [PLUGIN] : Unloaded GLAD2 Successfully!\n");
}