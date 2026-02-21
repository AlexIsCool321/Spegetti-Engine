#include <Noodle/Game.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>
#include <stdlib.h>

Game* LoadGame(const char* pName)
{
	Game* result = (Game*)malloc(sizeof(Game));
	if (!result)
	{
		printf("ERROR : FAILED TO ALLOCATE MEMORY!\n");
		return NULL;
	}

	result->m_game = PLUGNPLAY_LoadGame(pName);

	PLUGNPLAY_CallGameFunction("GameInit", NULL);

	return result;
}


void UnloadGame(Game* pGame)
{
	if (!pGame)
	{
		printf("ERROR : GAME IS NULL!\n");
		return;
	}
	
	PLUGNPLAY_UnloadGame(pGame->m_game);
	free(pGame);
}