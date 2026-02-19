#ifdef __linux__

#ifndef PLUGNPLAY_LINUX_LOADPLUGIN_H
#define PLUGNPLAY_LINUX_LOADPLUGIN_H

#include <PlugNPlay/Game.h>
#include <stdint.h>

Game* LINUX_LoadGame(const char* pName);

uint8_t LINUX_CallGameFunction(Game* pGame, void** result, const char* pName, void** args);

void LINUX_UnloadGame(Game* pGame);

#endif

#endif