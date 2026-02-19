#ifndef PLUGNPLAY_LOADPLUGIN_H
#define PLUGNPLAY_LOADPLUGIN_H

typedef struct
{
	void* m_handle;
	
	const char* m_name;
} PlugIn;

extern PlugIn* plugins[64];

PlugIn* LoadPlugIn(const char* pName);

void* CallPlugInFunction(const char* pName, void** args);

void UnloadPlugIn(PlugIn* pPlugIn);


void UnloadAllPlugIns();

#endif