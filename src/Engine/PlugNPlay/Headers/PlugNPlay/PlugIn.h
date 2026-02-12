#ifndef PLUGNPLAY_LOADPLUGIN_H
#define PLUGNPLAY_LOADPLUGIN_H

typedef struct
{
	void* m_handle;
	char m_name[128];
} PlugIn;

extern PlugIn* plugins[64];

PlugIn* LoadPlugIn(const char* pPath, const char* pName);

void* CallPlugInFunction(const char* pName, void** args);

void UnloadAllPlugIns();

#endif