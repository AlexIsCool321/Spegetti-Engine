#include <System/Init.h>
#include <PlugNPlay/PlugNPlay.h>

#include <stdlib.h>

void Init_System()
{
	CallPlugInFunction("PLUGIN_Init_System", NULL);
}

void Terminate_System()
{
	CallPlugInFunction("PLUGIN_Terminate_System", NULL);
}