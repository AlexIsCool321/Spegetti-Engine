#include <Renderer/Init.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>
#include <stdlib.h>

void InitRenderer(void* pProcAddress)
{
	{
		if (!pProcAddress) printf("ERROR : PROCEDURE ADDRESS IS NULL!\n");

		if (!pProcAddress) return;
	}

	void* args[1] =
	{
		pProcAddress
	};

	CallPlugInFunction("PLUGIN_InitRenderer", args);
}

void TerminateRenderer()
{
	CallPlugInFunction("PLUGIN_TerminateRenderer", NULL);
}