#include <Renderer/Camera.h>

#include <Math/Utils.h>

#include <stdio.h>

#include <math.h>

Camera* CurrentCamera;

Matrix CreateProjectionMatrix(float pFov, double pAspectRatio, float pNear)
{
	Matrix result = CreateEmptyMatrix();

	float tangent = tan(DegToRad(pFov/2));

	float top = pNear * tangent;
	float right = top * pAspectRatio;

/* Normal
 * pNear/right		0		0							0
 * 0			pNear/top	0							0
 * 0			0		-(pFar+pNear)/pFar-pNear	-2*pFar*pNear/pFar-pNear
 * 0			0		-1							0
*/

/* Infinite Far Plane
 * pNear/right	[0]	 0			[4]	 0	[8]		 0			[12]
 * 0			[1]	 pNear/top	[5]	 0	[9]		 0			[13]
 * 0			[2]	 0			[6]	-1	[10]	-2*pNear	[14]
 * 0			[3]	 0			[7]	-1	[11]	 0			[15]
*/

	result.m_values[0]	=	 pNear / right;
	result.m_values[5]	=	 pNear / top;
	result.m_values[10]	=	-1;
	result.m_values[11]	=	-1;
	result.m_values[14]	=	-2 * pNear;
	result.m_values[15]	=	 0;

	return result;
}

Camera CreateCamera(Vec3 pPosition, Vec3 pRotation, float pFov)
{
	Camera result;

	result.position = pPosition;
	result.rotation = pRotation;

	result.fov = pFov;

	result.m_projection = CreateProjectionMatrix(pFov, 4/3, 0.001f);

	return result;
}


void SetCurrentCamera(Camera* pCamera)
{
	CurrentCamera = pCamera;
}

Camera* GetCurrentCamera()
{
	return CurrentCamera;
}