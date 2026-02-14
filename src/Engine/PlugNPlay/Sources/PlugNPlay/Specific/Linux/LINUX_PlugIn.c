#include <PlugNPlay/Specific/Linux/LINUX_PlugIn.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include <string.h>

#include <dlfcn.h>

PlugIn* LINUX_LoadPlugIn(const char* pPath, const char* pName)
{
	PlugIn* result = (PlugIn*)malloc(sizeof(PlugIn));

	result->m_name = pName;

	char newPath[512];
	snprintf(newPath, 512, "./%s/lib%s.so", pPath, pName);

	printf("LOG : Loading [ %s ]!\n", newPath);

	void* handle = dlopen(newPath, RTLD_NOW | RTLD_LOCAL);
	if (!result->m_handle)
	{
		printf("ERROR : FAILED TO LOAD [ %s ]! : [ %s ]\n", newPath, dlerror());
		
		free(result);
		return NULL;
	}

	// Clear Error
	dlerror();

	printf("LOG : Loaded [ %s ] Successfully!\n", pName);

	return result;
}
   
uint8_t LINUX_CallPlugInFunction(PlugIn* pPlugIn, void** result, const char* pName, void** args)
{
	void* addr = dlsym(pPlugIn->m_handle, pName);
	if (!addr) return 0;

	typedef void* (*func_t)(void**);
	func_t func = (func_t)addr;

	*result = func(args);
	return 1;
}

void LINUX_UnloadPlugIn(PlugIn* pPlugIn)
{
	if (!pPlugIn)
	{
		printf("WARN : Plugin is NULL.\n");
		return;
	}
	printf("LOG : Unloading [ %s ]", pPlugIn->m_name);

	if (!dlclose(pPlugIn->m_handle))
	{
		printf("ERROR : FAILED TO UNLOAD [ %s ]! : [ %s ]\n", pPlugIn->m_name, dlerror());
		free(pPlugIn);
		pPlugIn = NULL;
		return;
	}

	free(pPlugIn);
	pPlugIn = NULL;

	printf("LOG : Successfuly unloaded [ %S ]!", pPlugIn->m_name);
}