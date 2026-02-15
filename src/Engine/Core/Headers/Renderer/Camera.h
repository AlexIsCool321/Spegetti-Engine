#ifndef RENDERER_CAMERA_H
#define RENDERER_CAMERA_H

#include <Math/Vec3.h>

typedef struct
{
	Vec3 position;
	Vec3 rotation;

	float fov;
} Camera;

Camera CreateCamera(Vec3 pPosition, Vec3 pRotation, float pFov);

#endif