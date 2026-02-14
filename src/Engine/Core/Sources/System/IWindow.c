#include <System/IWindow.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>
#include <stdlib.h>

IWindow* CreateWindow(unsigned int width, unsigned int height, const char* title)
{
	void* args[3] =
	{
		&width, &height, &title
	};

	return (IWindow*)CallPlugInFunction("PLUGIN_CreateWindow", args);
}


void UpdateWindow(IWindow* window)
{
	if (!window) return;

	void* args[1] =
	{
		window
	};

	CallPlugInFunction("PLUGIN_UpdateWindow", args);
}

uint8_t IsWindowOpen(IWindow* window)
{
	if (!window) return 0;

	void* args[1] =
	{
		window
	};

	intptr_t result = (intptr_t)CallPlugInFunction("PLUGIN_IsWindowOpen", args);

	uint8_t open = (uint8_t)result;
	
	return open;
}


void DestroyWindow(IWindow* window)
{
	if (!window) return;

	void* args[1] =
	{
		window
	};

	CallPlugInFunction("PLUGIN_DestroyWindow", args);
}