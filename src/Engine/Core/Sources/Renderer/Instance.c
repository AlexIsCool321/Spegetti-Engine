#include <Renderer/Instance.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>
#include <stdlib.h>

Instance* CreateInstance()
{
	Instance* result = (Instance*)CallPlugInFunction("PLUGIN_CreateInstance", NULL);
	if (!result)
	{
		printf("ERROR : [ PLUGIN_CreateInstance ] RETURNED NULL!\n");
		return NULL;
	}

	return result;
}