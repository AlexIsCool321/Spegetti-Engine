#include <System/Init.h>
#include <PlugNPlay/PlugNPlay.h>

#include <stdlib.h>

void InitSystem()
{
	CallPlugInFunction("PLUGIN_InitSystem", NULL);
}

void TerminateSystem()
{
	CallPlugInFunction("PLUGIN_TerminateSystem", NULL);
}