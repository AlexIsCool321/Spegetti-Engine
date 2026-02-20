#ifndef NOODLE_GAME_H
#define NOODLE_GAME_H

#include <PlugNPlay/Game.h>

typedef struct
{
	PLUGNPLAY_Game* m_game;
} Game;

Game* LoadGame(const char* pName);

void UnloadGame(Game* pGame);

#endif