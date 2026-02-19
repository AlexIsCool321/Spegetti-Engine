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

Vec2 GetMouseMotion(IWindow* pWindow)
{
	{
		if (!pWindow) printf("ERROR : WINDOW IS NULL!\n");

		if (!pWindow) return Vector2(0, 0);
	}

	void* args[1] =
	{
		pWindow
	};

	void* result = CallPlugInFunction("PLUGIN_GetMouseMotion", args);
	if (!result)
	{
		printf("ERROR : MOUSE MOTION IS NULL!\n");
		return Vector2(0, 0);
	}

	return *(Vec2*)result;
}

Vec2 GetMousePosition(IWindow* pWindow)
{
	{
		if (!pWindow) printf("ERROR : WINDOW IS NULL!\n");

		if (!pWindow) return Vector2(0, 0);
	}

	void* args[1] =
	{
		pWindow
	};

	void* result = CallPlugInFunction("PLUGIN_GetMousePosition", args);
	if (!result)
	{
		printf("ERROR : MOUSE POSITION IS NULL!\n");
		return Vector2(0, 0);
	}

	return *(Vec2*)result;
}