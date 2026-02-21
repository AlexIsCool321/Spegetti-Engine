#include <Demo/FreeCam.h>

#include <stdio.h>
#include <stdlib.h>

void* CreateFreeCam(void** pArgs)
{
	const char* pName;
	const char* pType;
	{
		if (!pArgs[0]) printf("ERROR : NAME IS NULL!\n");
		if (!pArgs[1]) printf("ERROR : TYPE IS NULL!\n");

		if (!pArgs[0] || !pArgs[1]) return NULL;\

		pName = *(const char**)pArgs[0];
		pType = *(const char**)pArgs[1];
	}

	FreeCam* result = (FreeCam*)malloc(sizeof(FreeCam));
	if (!result)
	{
		printf("ERROR : FAILED TO ALLOCATE MEMORY!\n");

		return NULL;
	}

	result->base.name = pName;
	result->base.type = pType;

	result->base.position	= Vector3(0, 0, 0);
	result->base.rotation	= Vector3(0, 0, 0);
	result->base.scale		= Vector3(1, 1, 1);

	result->m_camera = CreateCamera(Vector3(0, 0, 0), Vector3(0, 0, 0), 90.0f);

	return result;
}

void UpdateFreeCam(void** pArgs)
{
	FreeCam* pEntity;
	{
		if (!pArgs[0]) printf("ERROR : ENTITY IS NULL!\n");

		if (!pArgs[0]) return;

		pEntity = (FreeCam*)pArgs[0];
	}
}

void DestroyFreeCam(void** pArgs)
{
	FreeCam* pEntity;
	{
		if (!pArgs[0]) printf("ERROR : ENTITY IS NULL!\n");

		if (!pArgs[0]) return;

		pEntity = (FreeCam*)pArgs[0];
	}
}