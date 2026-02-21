#include <System/Input.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>

uint8_t IsKeyPressed(KEY pKey)
{
	void* args[1] =
	{
		&pKey
	};

	return (uint8_t)(intptr_t)CallPlugInFunction("PLUGIN_IsKeyPressed", args);
}

Vec2 GetMouseMotion()
{
	void* result = CallPlugInFunction("PLUGIN_GetMouseMotion", NULL);
	if (!result)
	{
		printf("ERROR : MOUSE MOTION IS NULL!\n");
		return Vector2(0, 0);
	}

	return *(Vec2*)result;
}

Vec2 GetMousePosition()
{
	void* result = CallPlugInFunction("PLUGIN_GetMousePosition", NULL);
	if (!result)
	{
		printf("ERROR : MOUSE POSITION IS NULL!\n");
		return Vector2(0, 0);
	}

	return *(Vec2*)result;
}