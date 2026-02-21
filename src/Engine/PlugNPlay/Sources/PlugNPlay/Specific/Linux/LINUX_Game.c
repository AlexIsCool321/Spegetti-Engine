#ifdef __linux__

#include <PlugNPlay/Specific/Linux/LINUX_Game.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include <string.h>

#include <dlfcn.h>

PLUGNPLAY_Game* LINUX_LoadGame(const char* pName)
{
	PLUGNPLAY_Game* result = (PLUGNPLAY_Game*)malloc(sizeof(PLUGNPLAY_Game));

	result->m_name = pName;

	char newPath[512];
	snprintf(newPath, sizeof(newPath), "./%s/libClient.so", pName);

	printf("LOG : Loading [ %s ]!\n", newPath);

	result->m_handle = dlopen(newPath, RTLD_NOW | RTLD_LOCAL);   
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


uint8_t LINUX_CallGameFunction(PLUGNPLAY_Game* pGame, void** result, const char* pName, void** args)
{
	void* addr = dlsym(pGame->m_handle, pName);
	if (!addr) return 0;

	typedef void* (*func_t)(void**);
	func_t func = (func_t)addr;

	*result = func(args);
	return 1;
}


void LINUX_UnloadGame(PLUGNPLAY_Game* pGame)
{
	if (!pGame)
	{
		printf("WARN : Game is already NULL.\n");
		return;
	}
	
	printf("LOG : Unloading [ %s ]\n", pGame->m_name);

	if (!dlclose(pGame->m_handle))
	{
		printf("ERROR : FAILED TO UNLOAD [ %s ]! : [ %s ]\n", pGame->m_name, dlerror());

		free(pGame);
		pGame = NULL;
		return;
	}

	free(pGame);
	pGame = NULL;

	printf("LOG : Successfuly unloaded [ %S ]!\n", pGame->m_name);
}

#endif