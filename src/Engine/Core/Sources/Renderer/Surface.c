#include <Renderer/Surface.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>
#include <stdlib.h>

Surface* CreateSurface()
{
	Surface* result = (Surface*)CallPlugInFunction("PLUGIN_CreateSurface", NULL);
	if (!result)
	{
		printf("ERROR : [ PLUGIN_CreateSurface ] RETURNED NULL!\n");
		return NULL;
	}

	return result;
}