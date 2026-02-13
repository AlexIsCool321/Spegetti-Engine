#include <System/IWindow.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>
#include <stdlib.h>

IWindow* CreateWindow(unsigned int width, unsigned int height, const char* title)
{
	{
		if (!title) printf("ERROR : TITLE IS NULL!\n");

		if (!title) return NULL;
	}

	void* args[3] =
	{
		&width, &height, &title
	};

	return (IWindow*)CallPlugInFunction("PLUGIN_CreateWindow", args);
}


void UpdateWindow(IWindow* window)
{
	{
		if (!window) printf("ERROR : WINDOW IS NULL!\n");

		if (!window) return;
	}

	void* args[1] =
	{
		window
	};

	CallPlugInFunction("PLUGIN_UpdateWindow", args);
}

void SwapWindowBuffers(IWindow* window)
{
	{
		if (!window) printf("ERROR : WINDOW IS NULL!\n");

		if (!window) return;
	}

	void* args[1] =
	{
		window
	};

	CallPlugInFunction("PLUGIN_SwapWindowBuffers", args);
}


uint8_t IsWindowOpen(IWindow* window)
{
	{
		if (!window) printf("ERROR : WINDOW IS NULL!\n");

		if (!window) return 0;
	}

	return window->m_open;
}


void DestroyWindow(IWindow* window)
{
	{
		if (!window) printf("WARN : Window is already NULL.\n");

		if (!window) return;
	}

	void* args[1] =
	{
		window
	};

	CallPlugInFunction("PLUGIN_DestroyWindow", args);
}