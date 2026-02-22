#include <System/Input.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>
#include <stdlib.h>

uint8_t IsKeyPressed(KEY pKey)
{
	void* args[1] =
	{
		&pKey
	};
	uint8_t* result = (uint8_t*)CallPlugInFunction("PLUGIN_IsKeyPressed", args);
	if (!result)
	{
		printf("ERROR : [ PLUGIN_IsKeyPressed ] RETURN NULL!\n");
		return 0;
	}

	uint8_t pressed = *result;
	free(result);

	return pressed;
}

Vec2 GetMouseMotion()
{
	Vec2* result = (Vec2*)CallPlugInFunction("PLUGIN_GetMouseMotion", NULL);
	if (!result)
	{
		printf("ERROR : [ PLUGIN_GetMouseMotion ] RETURN NULL!\n");
		return Vector2(0, 0);
	}

	return *result;
}

Vec2 GetMousePosition()
{
	Vec2* result = (Vec2*)CallPlugInFunction("PLUGIN_GetMousePosition", NULL);
	if (!result)
	{
		printf("ERROR : [ PLUGIN_GetMousePosition ] RETURN NULL!\n");
		return Vector2(0, 0);
	}

	return *result;
}