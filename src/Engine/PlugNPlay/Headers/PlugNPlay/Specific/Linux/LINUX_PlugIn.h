#ifndef PLUGNPLAY_LINUX_LOADPLUGIN_H
#define PLUGNPLAY_LINUX_LOADPLUGIN_H

#include <PlugNPlay/PlugIn.h>
#include <stdint.h>

PlugIn* LINUX_LoadPlugIn(const char* pPath, const char* pName);

uint8_t LINUX_CallPlugInFunction(PlugIn* pPlugIn, void** result, const char* pName, void** args);

void LINUX_UnloadPlugIn(PlugIn* pPlugIn);

#endif