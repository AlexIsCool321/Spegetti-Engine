#include <System/Init.h>
#include <PlugNPlay/PlugNPlay.h>

#include <System/SearchPath.h>

#include <stdlib.h>
#include <string.h>

void InitSystem()
{
	// Allocate memory for SearchPathes
	// Puts all the SearchPathes all next to each other in memory
	char* SIZE = (char*)malloc(sizeof(const char*) * MAX_SEARCHPATHES);
	memcpy(SearchPathes, SIZE, sizeof(SIZE));

	CallPlugInFunction("PLUGIN_InitSystem", NULL);
}

void TerminateSystem()
{
	ClearSearchPathes();
	
	CallPlugInFunction("PLUGIN_TerminateSystem", NULL);
}