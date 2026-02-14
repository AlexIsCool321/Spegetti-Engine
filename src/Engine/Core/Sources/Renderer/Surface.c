#include <Renderer/Surface.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>
#include <stdlib.h>

Surface* CreateSurface()
{
	void* result = CallPlugInFunction("PLUGIN_CreateSurface", NULL);

	return (Surface*)result;
}