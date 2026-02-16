#ifndef RENDERER_CAMERA_H
#define RENDERER_CAMERA_H

#include <Math/Vec3.h>
#include <Math/Matrix.h>

typedef struct
{
	Vec3 position;
	Vec3 rotation;

	float fov;

	Matrix m_projection;
} Camera;

Matrix CreateProjectionMatrix(float pFov, double pAspectRatio, float pNear);

Camera CreateCamera(Vec3 pPosition, Vec3 pRotation, float pFov);

#endif