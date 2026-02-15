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
	//result = MultiplyMatricies(result, rotationY);
	//result = MultiplyMatricies(result, rotationZ);
	//result = MultiplyMatricies(result, rotationX);

	return result;
}