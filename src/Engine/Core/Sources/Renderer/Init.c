#include <Renderer/Init.h>
#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>
#include <stdlib.h>

void InitRenderer(LoadProcAddress* loadProcAddres)
{
	{
		if (!loadProcAddres) printf("ERROR : PROCUDER ADDRESS IS NULL!\n");

		if (!loadProcAddres) return;
	}

	void* args[1] =
	{
		loadProcAddres
	};

	CallPlugInFunction("PLUGIN_InitRenderer", args);
}

void TerminateRenderer()
{
	CallPlugInFunction("PLUGIN_TerminateRenderer", NULL);
}