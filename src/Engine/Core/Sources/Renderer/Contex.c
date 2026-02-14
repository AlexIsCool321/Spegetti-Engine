#include <Renderer/Contex.h>

void CreateWindowContex(IWindow* window)
{
	if (!window) return;

	void* args[1] =
	{
		window
	};

	CallPlugInFunction("PLUGIN_CreateWindowContex", args);
}