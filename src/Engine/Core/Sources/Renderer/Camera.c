#include <Renderer/Camera.h>

Camera CreateCamera(Vec3 pPosition, Vec3 pRotation, float pFov)
{
	Camera result;

	result.position = pPosition;
	result.rotation = pRotation;

	result.fov = pFov;

	return result;
}