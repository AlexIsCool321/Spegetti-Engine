#ifdef __linux__

#ifndef PLUGNPLAY_LINUX_LOADPLUGIN_H
#define PLUGNPLAY_LINUX_LOADPLUGIN_H

#include <PlugNPlay/Game.h>
#include <stdint.h>

PLUGNPLAY_Game* LINUX_LoadGame(const char* pName);

uint8_t LINUX_CallGameFunction(PLUGNPLAY_Game* pGame, void** result, const char* pName, void** args);

void LINUX_UnloadGame(PLUGNPLAY_Game* pGame);

#endif

#endif