#include <Renderer/Init.h>

#include <stdlib.h>

void InitRenderer()
{
	CallPlugInFunction("PLUGIN_InitRenderer", NULL);
}

void TerminateRenderer()
{
	CallPlugInFunction("PLUGIN_TerminateRenderer", NULL);
}