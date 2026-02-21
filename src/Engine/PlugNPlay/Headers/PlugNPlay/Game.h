#ifndef PLUGNPLAY_GAME_H
#define PLUGNPLAY_GAME_H

#include <stdint.h>

#define MAX_GAMES 64

typedef struct
{
	void* m_handle;
	
	const char* m_name;
} PLUGNPLAY_Game;

extern PLUGNPLAY_Game* games[MAX_GAMES];
extern uint8_t gameIndex;

PLUGNPLAY_Game* PLUGNPLAY_LoadGame(const char* pName);

void* PLUGNPLAY_CallGameFunction(const char* pName, void** args);

void PLUGNPLAY_UnloadGame(PLUGNPLAY_Game* pGame);

void PLUGNPLAY_UnloadAllGames();

#endif