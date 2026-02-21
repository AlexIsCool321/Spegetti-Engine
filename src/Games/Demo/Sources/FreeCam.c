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

		if (!pArgs[0] || !pArgs[1]) return NULL;

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
	SetCurrentCamera(&result->m_camera);

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

	// Rotation
	pEntity->m_camera.rotation.y += GetMouseMotion().x * 0.005;
	pEntity->m_camera.rotation.x += GetMouseMotion().y * 0.005;

	pEntity->m_camera.rotation.x = ClampFloat(pEntity->m_camera.rotation.x, DegToRad(-89.9), DegToRad(89.9));


	// Position
	Vec3 InputDirection = Vector3
	(
		IsKeyPressed(KEY_D)		- IsKeyPressed(KEY_A),
		IsKeyPressed(KEY_SPACE)	- IsKeyPressed(KEY_LEFT_SHIFT),
		IsKeyPressed(KEY_W)		- IsKeyPressed(KEY_S)
	);

	Vec3 Forward = Vector3
	(
		InputDirection.z * sin(pEntity->m_camera.rotation.y),
		0,
		InputDirection.z * cos(pEntity->m_camera.rotation.y)
	);
	Forward = ScaleVector3(Forward, 0.1333);

	Vec3 Right = Vector3
	(
		InputDirection.x * -cos(pEntity->m_camera.rotation.y),
		0,
		InputDirection.x * sin(pEntity->m_camera.rotation.y)
	);
	Right = ScaleVector3(Right, 0.1333);

		
	pEntity->m_camera.position = AddVector3(pEntity->m_camera.position, Forward);
	pEntity->m_camera.position = AddVector3(pEntity->m_camera.position, Right);

	pEntity->m_camera.position.y += 0.1333 * InputDirection.y;
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