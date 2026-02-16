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

	char* result = (char*)malloc(MAX_FILESIZE);
	size_t currentFileSize = 0;

	char buffer[512];

	while (fgets(buffer, sizeof(buffer), reader))
	{
		size_t bufferSize = strlen(buffer);

		if (currentFileSize + bufferSize >= MAX_FILESIZE - 1)
		{
			printf("ERROR : FILE IS EXEDED MAX SIZE OF [ %i ]!\n", MAX_FILESIZE);
			
			free(result);
			fclose(reader);
			return "";
		}
		memcpy(result + currentFileSize, buffer, bufferSize);
		currentFileSize += bufferSize;
	}

	result[currentFileSize] = '\0';
	
	fclose(reader);

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