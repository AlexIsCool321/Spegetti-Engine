#include <Noodle/Entity.h>
#include <Noodle/Game.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>
#include <stdlib.h>

Entity* CreateEntity(const char* pName, const char* pType)
{
	char functionName[512];
	snprintf(functionName, sizeof(functionName), "Create%s", pType);
	
	Entity* result;

	void* args[2] =
	{
		&pName,
		&pType
	};

	for (uint8_t i = 0; i < gameIndex; i++)
	{
		result = (Entity*)PLUGNPLAY_CallGameFunction(functionName, args);
		if (result)
		{
			break;
		}
	}

	if (!result)
	{
		printf("ERROR : FAILED TO FIND ENTITY WITH THE TYPE [ %s ]!\n", pType);
		return NULL;
	}

	return result;
}


void UpdateEntity(Entity* pEntity)
{
	if (!pEntity)
	{
		printf("ERROR : ENTITY IS NULL!\n");
		return;
	}

	char functionName[512];
	snprintf(functionName, sizeof(functionName), "Update%s", pEntity->type);

	void* args[1] =
	{
		pEntity
	};

	for (uint8_t i = 0; i < gameIndex; i++)
	{
		PLUGNPLAY_CallGameFunction(functionName, args);
	}
}


void DestroyEntity(Entity* pEntity)
{
	if (!pEntity)
	{
		printf("ERROR : ENTITY IS NULL!\n");
		return;
	}

	char functionName[512];
	snprintf(functionName, sizeof(functionName), "Destroy%s", pEntity->type);

	void* args[1] =
	{
		pEntity
	};

	for (uint8_t i = 0; i < gameIndex; i++)
	{
		PLUGNPLAY_CallGameFunction(functionName, args);
	}

	free(pEntity);
}