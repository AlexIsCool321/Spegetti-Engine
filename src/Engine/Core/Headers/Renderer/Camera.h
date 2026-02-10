#ifndef RENDERER_CAMERA_H
#define RENDERER_CAMERA_H

#include <Math/Vec3.h>

typedef struct
{
	float fov;

	Vec3 position;
	Vec3 rotaion;
} Camera;

extern Camera* CurrentCamera;

#endif