#include <System/IWindow.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>
#include <stdlib.h>

IWindow* CurrentWindow;

IWindow* CreateWindow(unsigned int pWidth, unsigned int pHeight, const char* pTitle)
{
	void* args[3] =
	{
		&pWidth, &pHeight, &pTitle
	};

	IWindow* result = (IWindow*)CallPlugInFunction("PLUGIN_CreateWindow", args);
	if (!result)
	{
		printf("ERROR : [ PLUGIN_CreateWindow ] RETURNED NULL!\n");
		return NULL;
	}

	return result;
}


void SetCurrentWindow(IWindow* pWindow)
{
	if (!pWindow)
	{
		printf("ERROR : WINDOW IS NULL!\n");
		return;
	}

	CurrentWindow = pWindow;
}

IWindow* GetCurrentWindow()
{
	if (!CurrentWindow) printf("WARN : CurrentWindow is NULL, please use [ SetCurrentWindow ].\n");

	return CurrentWindow;
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

void SwapWindowBuffers(IWindow* pWindow)
{
	{
		if (!pWindow) printf("ERROR : WINDOW IS NULL!\n");

		if (!pWindow) return;
	}

	void* args[1] =
	{
		pWindow
	};

	CallPlugInFunction("PLUGIN_SwapWindowBuffers", args);
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

	uint8_t* result = (uint8_t*)CallPlugInFunction("PLUGIN_IsWindowOpen", args);
	if (!result)
	{
		printf("ERROR : [ PLUGIN_IsWindowOpen ] RETURNED NULL!\n");
		return 0;
	}

	uint8_t open = *result;
	free(result);
	
	return open;
}

Vec2 GetWindowSize(IWindow* pWindow)
{
	{
		if (!pWindow) printf("ERROR : WINDOW IS NULL!\n");

		if (!pWindow) return Vector2(0, 0);
	}

	void* args[1] =
	{
		pWindow
	};

	Vec2* result = (Vec2*)CallPlugInFunction("PLUGIN_GetWindowSize", args);
	if (!result)
	{
		printf("ERROR : [ PLUGIN_GetWindowSize ] RETURNED NULL!\n");
		return Vector2(0, 0);
	}

	Vec2 size = *result;
	free(result);

	return size;
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

	if (pWindow) free(pWindow);
}