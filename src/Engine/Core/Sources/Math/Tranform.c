#include <Math/Tranform.h>

#include <stdio.h>

#include <math.h>

Matrix CreateTransform(Vec3 pPosition, Vec3 pRotation, Vec3 pScale)
{
	Matrix result = CreateEmptyMatrix();

	// Scale
	result.m_values[0]	= pScale.x;
	result.m_values[5]	= pScale.y;
	result.m_values[10]	= pScale.z;

	// Position
	result.m_values[12]	= pPosition.x;
	result.m_values[13]	= pPosition.y;
	result.m_values[14]	= pPosition.z;

	// Rotation
	Matrix rotationX = CreateEmptyMatrix();
	rotationX.m_values[5]	=	 sin(pRotation.x);
	rotationX.m_values[6]	=	-sin(pRotation.x);
	rotationX.m_values[9]	=	 sin(pRotation.x);
	rotationX.m_values[10]	=	 cos(pRotation.x);

	Matrix rotationY = CreateEmptyMatrix();
	rotationY.m_values[0]	=	 cos(pRotation.y);
	rotationY.m_values[2]	=	 sin(pRotation.y);
	rotationY.m_values[8]	=	-sin(pRotation.y);
	rotationY.m_values[10]	=	 cos(pRotation.y);

	Matrix rotationZ = CreateEmptyMatrix();
	rotationZ.m_values[0]	=	 cos(pRotation.z);
	rotationZ.m_values[1]	=	 sin(pRotation.z);
	rotationZ.m_values[4]	=	 -sin(pRotation.z);
	rotationZ.m_values[5]	=	 cos(pRotation.z);
	
	// Combine
	result = MultiplyMatricies(result, rotationY);
	result = MultiplyMatricies(result, rotationZ);
	result = MultiplyMatricies(result, rotationX);

	return result;
}

Matrix LookAtMatrix(Vec3 pEye, Vec3 pTarget)
{
	Matrix result = CreateEmptyMatrix();

	Vec3 forward	= Normalized(SubtractVector3(pEye, pTarget));
	Vec3 right		= Normalized(CrossVector3(Vector3(0, 1, 0), forward));
	Vec3 up			= CrossVector3(forward, right);
	

	float values[16] =
	{
		right.x,	right.y,	right.z,	0,
		up.x,		up.y,		up.z,		0,
		forward.x,	forward.y,	forward.z,	0,
		pEye.x,		pEye.y,		pEye.z,		1
	};

//	float values[16] =
//	{
//		right.x,	up.x,	forward.x,	pEye.x,
//		right.y,	up.y,	forward.y,	pEye.y,
//		right.z,	up.z,	forward.z,	pEye.z,
//		0,			0,		0,			1
//	};

//	float values[16] =
//	{
//		1,	2,	3,	4,
//		5,	6,	7,	8,
//		9,	10,	11,	12,
//		13,	14,	15,	16
//	};

	for (uint8_t i = 0; i < 16; i++)
	{
		result.m_values[i] = values[i];
	}

	return result;
}