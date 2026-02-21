#ifndef FREECAM_H
#define FREECAM_H

#include <Demo/Demo.h>

typedef struct
{
	Entity base;

	Camera m_camera;
} FreeCam;

void* CreateFreeCam(void** pArgs);

void UpdateFreeCam(void** pArgs);

void DestroyFreeCam(void** pArgs);

#endif