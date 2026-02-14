#include <System/Contex.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>

void AttachSurfaceToWindow(IWindow* pWindow, Surface* pSurface)
{
	{
		if (!pWindow) printf("ERROR : WINDOW IS NULL!\n");
		if (!pSurface) printf("ERROR : SURFACE IS NULL!\n");;

		if (!pWindow || !pSurface) return;
	}

	void* args[2] =
	{
		pWindow,
		pSurface
	};

	CallPlugInFunction("PLUGIN_AttachSurfaceToWindow", args);
}