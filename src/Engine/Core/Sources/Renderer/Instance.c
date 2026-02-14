#include <Renderer/Instance.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>
#include <stdlib.h>

Instance* CreateInstance()
{
	void* result = CallPlugInFunction("PLUGIN_CreateInstance", NULL);

	return (Instance*)result;
}