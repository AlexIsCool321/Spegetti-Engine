#include <System/Contex.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>

void AttachSurfaceAndInstanceToWindow(IWindow* pWindow, Surface* pSurface, Instance* pInstace)
{
	{
		if (!pWindow) printf("ERROR : WINDOW IS NULL!\n");

		if (!pWindow) return;
	}

	void* args[3] =
	{
		pWindow,
		pSurface,
		pInstace
	};

	CallPlugInFunction("PLUGIN_AttachSurfaceAndInstanceToWindow", args);
}