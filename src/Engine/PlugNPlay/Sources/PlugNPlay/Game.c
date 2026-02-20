#include <PlugNPlay/Game.h>

#ifdef __linux__
	#include <PlugNPlay/Specific/Linux/LINUX_Game.h>
#endif

#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

#define MAX_GAMES 64

PLUGNPLAY_Game* games[MAX_GAMES];
uint8_t gameIndex = 0;

PLUGNPLAY_Game* PLUGNPLAY_LoadGame(const char* pName)
{
	PLUGNPLAY_Game* result = NULL;

#ifdef __linux__
	result = LINUX_LoadGame(pName);
#endif

	if (!result)
	{
		printf("ERROR : FAILED TO LOAD GAME! : [ %s ]\n", pName);
		return NULL;
	}

	games[gameIndex] = result;
	gameIndex++;

	return result;
}

void* PLUGNPLAY_CallGameFunction(const char* pName, void** args)
{
	void* result = NULL;
	uint8_t successful = 0;

	for (uint8_t i = 0; i < gameIndex; i++)
	{
		if (!games[i]) continue;

#ifdef __linux__
		if (LINUX_CallGameFunction(games[i], &result, pName, args))
		{
			successful = 1;
		}
#endif
	}

	if (!successful)
	{
		printf("WARN : No game has an implemntation for [ %s ]!\n", pName);
		return NULL;
	}

	return result;
}

void PLUGNPLAY_UnloadGame(PLUGNPLAY_Game* pGame)
{
#ifdef __linux__
	LINUX_UnloadGame(pGame);
#endif
}



void PLUGNPLAY_UnloadAllGames()
{
	printf("LOG : Unloading ALL Games!\n");

	for (uint8_t i = 0; i < gameIndex; i++)
	{
		PLUGNPLAY_UnloadGame(games[i]);
	}

	printf("LOG : Unloaded ALL Games Successfully!\n");
}