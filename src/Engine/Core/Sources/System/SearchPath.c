#include <System/SearchPath.h>

#include <stdio.h>
#include <stdlib.h>

const char* SearchPathes[MAX_SEARCHPATHES];
uint8_t SearchPathIndex = 0;

void AddSearchPath(const char* pPath)
{
	if (!pPath)
	{
		printf("ERROR : PATH IS NULL!\n");
		return;
	}

	SearchPathes[SearchPathIndex] = pPath;
	SearchPathIndex++;
}


const char* ReadFile(const char* pFile)
{
	return "";
}


void ClearSearchPathes()
{
	for (uint8_t i = 0; i < SearchPathIndex; i++)
	{
		SearchPathes[i] = NULL;
	}
	SearchPathIndex = 0;
}