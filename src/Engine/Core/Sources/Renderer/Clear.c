#include <Renderer/Clear.h>

#include <PlugNPlay/PlugNPlay.h>

void ClearScreen(Vec3 pColor)
{
	void* args[1] =
	{
		&pColor
	};

	CallPlugInFunction("PLUGIN_ClearScreen", args);
}