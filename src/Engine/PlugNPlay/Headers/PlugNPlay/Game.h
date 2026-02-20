#ifndef GAME_H
#define GAME_H

typedef struct
{
	void* m_handle;
	
	const char* m_name;
} PLUGNPLAY_Game;

extern PLUGNPLAY_Game* games[64];

PLUGNPLAY_Game* PLUGNPLAY_LoadGame(const char* pName);

void* PLUGNPLAY_CallGameFunction(const char* pName, void** args);

void PLUGNPLAY_UnloadGame(PLUGNPLAY_Game* pGame);

void PLUGNPLAY_UnloadAllGames();

#endif