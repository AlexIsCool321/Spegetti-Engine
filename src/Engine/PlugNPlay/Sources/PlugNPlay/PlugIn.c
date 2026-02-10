#include <PlugNPlay/PlugIn.h>

#ifdef __linux__
#include <PlugNPlay/Specific/Linux/LINUX_PlugIn.h>
#endif

#include <stdio.h>
#include <stdarg.h>

#define MAX_PLUGINS 64

PlugIn* plugins[MAX_PLUGINS];
uint8_t pluginIndex = 0;

PlugIn* LoadPlugIn(const char* pPath, const char* pName)
{
	PlugIn* result = NULL;

#ifdef __linux__
	result = LINUX_LoadPlugIn(pPath, pName);
#endif

	if (!result)
	{
		printf("ERROR : FAILED TO LOAD PLUGIN! : [ %s ]\n", pName);
		return NULL;
	}

	plugins[pluginIndex] = result;
	pluginIndex++;

	return result;
}

void* CallPlugInFunction(const char* pName, void** args)
{
	void* result = NULL;
	uint8_t successful = 0;

	for (uint8_t i = 0; i < pluginIndex; i++)
	{
		if (!plugins[i]) continue;

#ifdef __linux__
		if (LINUX_CallPlugInFunction(plugins[i], &result, pName, args))
		{
			successful = 1;
		}
#endif
	}

	if (!successful)
	{
		printf("WARN : No plugin function! : [ %s ]\n", pName);
		return NULL;
	}

	return result;
}