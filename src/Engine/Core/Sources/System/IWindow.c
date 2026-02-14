#include <System/IWindow.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>
#include <stdlib.h>

IWindow* CreateWindow(unsigned int pWidth, unsigned int pHeight, const char* pTitle)
{
	void* args[3] =
	{
		&pWidth, &pHeight, &pTitle
	};

	return (IWindow*)CallPlugInFunction("PLUGIN_CreateWindow", args);
}


void UpdateWindow(IWindow* pWindow)
{
	{
		if (!pWindow) printf("ERROR : WINDOW IS NULL!\n");

		if (!pWindow) return;
	}

	void* args[1] =
	{
		pWindow
	};

	CallPlugInFunction("PLUGIN_UpdateWindow", args);
}

uint8_t IsWindowOpen(IWindow* pWindow)
{
	{
		if (!pWindow) printf("ERROR : WINDOW IS NULL!\n");

		if (!pWindow) return 0;
	}

	void* args[1] =
	{
		pWindow
	};

	intptr_t result = (intptr_t)CallPlugInFunction("PLUGIN_IsWindowOpen", args);

	uint8_t open = (uint8_t)result;
	
	return open;
}


void* GetWindowProcedureAddress(IWindow* pWindow)
{
	{
		if (!pWindow) printf("ERROR : WINDOW IS NULL!\n");

		if (!pWindow) return NULL;
	}

	void* args[1] =
	{
		pWindow
	};

	return CallPlugInFunction("PLUGIN_GetWindowProcedureAddress", args);
}


void DestroyWindow(IWindow* pWindow)
{
	{
		if (!pWindow) printf("WARN : Window is already NULL.\n");

		if (!pWindow) return;
	}

	void* args[1] =
	{
		pWindow
	};

	CallPlugInFunction("PLUGIN_DestroyWindow", args);
}