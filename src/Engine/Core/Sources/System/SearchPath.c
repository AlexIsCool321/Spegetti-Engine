#include <System/SearchPath.h>

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

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
	FILE* reader;

	for (uint8_t i = 0; i < SearchPathIndex; i++)
	{
		char path[512];
		sprintf(path, "%s/%s", SearchPathes[i], pFile);

		reader = fopen(path, "r");

		if (reader)
		{
			break;
		}
	}

	if (!reader)
	{
		printf("ERROR : FAILED TO OPEN [ %s ]!\n", pFile);

		fclose(reader);
		return "";
	}

	char buffer[512];

	char file[MAX_FILESIZE] = "";

	while(fgets(buffer, sizeof(buffer), reader))
	{
		sprintf(file, "%s%s", file, buffer);
	}

	fclose(reader);

	char* result = (char*)malloc(sizeof(file));
	result = file;

	return result;
}


void ClearSearchPathes()
{
	for (uint8_t i = 0; i < SearchPathIndex; i++)
	{
		SearchPathes[i] = NULL;
	}
	SearchPathIndex = 0;
}