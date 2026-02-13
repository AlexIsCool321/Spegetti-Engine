#include <Renderer/CreateContex.h>

void CreateContex(IWindow* pWindow)
{
	{
		if (!pWindow) printf("ERROR : WINDOW IS NULL!\n");

		if (!pWindow) return;
	}

	void* args[1] =
	{
		pWindow
	};

	CallPlugInFunction("PLUGIN_CreateContex", args);
}

void DestroyContex(IWindow* pWindow)
{
	{
		if (!pWindow) printf("ERROR : WINDOW IS NULL!\n");

		if (!pWindow) return;
	}

	void* args[1] =
	{
		pWindow
	};

	CallPlugInFunction("PLUGIN_DestroyContex", args);
}