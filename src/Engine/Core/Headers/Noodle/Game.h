#ifndef NOODLE_GAME_H
#define NOODLE_GAME_H

#include <stdint.h>

#define MAX_GAMES 64

typedef struct
{
	void* m_game;
} Game;

Game* LoadGame(const char* pName);

void UnloadGame(Game* pGame);

#endif