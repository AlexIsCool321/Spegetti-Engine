#ifndef GAME_H
#define GAME_H

typedef struct
{
	void* m_handle;
	
	const char* m_name;
} Game;

extern Game* games[64];

Game* LoadGame(const char* pName);

void* CallGameFunction(const char* pName, void** args);

void UnloadGame(Game* pGame);

void UnloadAllGames();

#endif