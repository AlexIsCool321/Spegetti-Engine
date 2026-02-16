#include <System/Input.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>

uint8_t IsKeyPressed(IWindow* pWindow, KEY pKey)
{
	{
		if (!pWindow) printf("ERROR : WINDOW IS NULL!\n");

		if (!pWindow) return 0;
	}

	void* args[2] =
	{
		pWindow,
		&pKey
	};

	return (uint8_t)(intptr_t)CallPlugInFunction("PLUGIN_IsKeyPressed", args);
}