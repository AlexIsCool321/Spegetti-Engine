#include <PlugNPlay/Specific/Linux/LINUX_PlugIn.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include <string.h>

#include <dlfcn.h>

PlugIn* LINUX_LoadPlugIn(const char* pPath, const char* pName)
{
	PlugIn* result = (PlugIn*)malloc(sizeof(PlugIn));
	memcpy(result->m_name, pName, sizeof(result->m_name));

	char newPath[512];
	snprintf(newPath, 512, "./%s/lib%s.so", pPath, pName);

	printf("LOG : Loading [ %s ]!\n", newPath);

	result->m_handle = dlopen(newPath, RTLD_GLOBAL | RTLD_NOW);
	if (!result->m_handle)
	{
		printf("ERROR : FAILED TO LOAD [ %s ]!\n", newPath);
		printf("LOG : %s\n", dlerror());

		return NULL;
	}

	// Clear Error
	dlerror();

	printf("LOG : Loaded [ %s ] Successfully!\n", pName);

	return result;
}

typedef void* (*pluginFunction)(void**);

uint8_t LINUX_CallPlugInFunction(PlugIn* pPlugIn, void** result, const char* pName, void** args)
{
	void* addr = dlsym(pPlugIn->m_handle, pName);
	if (!addr) return 0;

	pluginFunction func = (pluginFunction)addr;

	(*result) = func(args);
	return 1;
}

void LINUX_UnloadPlugIn(PlugIn* pPlugIn)
{
	uint8_t succses = dlclose(pPlugIn->m_handle);

	if (succses)
	{
		printf("WARN : Failed to unload plugIn [ %s ]. : [ %s ]\n", pPlugIn->m_name, dlerror());
	}
}