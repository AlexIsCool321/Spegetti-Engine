#include <Renderer/Screen.h>

#include <PlugNPlay/PlugNPlay.h>

void ClearScreen(Vec3 pColor)
{
	void* args[1] =
	{
		&pColor
	};

	CallPlugInFunction("PLUGIN_ClearScreen", args);
}

void ResizeScreen(Vec2 pSize)
{
	void* args[1] =
	{
		&pSize
	};

	CallPlugInFunction("PLUGIN_ResizeScreen", args);
}