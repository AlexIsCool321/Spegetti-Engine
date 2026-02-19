#include <Math/Vec3.h>

#include <math.h>

Vec3 Vector3(float pX, float pY, float pZ)
{
	Vec3 result;

	result.x = pX;
	result.y = pY;
	result.z = pZ;

	return result;
}


Vec3 Normalized(Vec3 pVector)
{
	Vec3 result = pVector;

	float magnitude =
	sqrt(
		(pVector.x * pVector.x) +
		(pVector.y * pVector.y) +
		(pVector.z * pVector.z)
	);

	if (magnitude == 0)
	{
		return Vector3(0, 0, 0);
	}

	result.x /= magnitude;
	result.y /= magnitude;
	result.z /= magnitude;

	return result;
}

Vec3 CrossVector3(Vec3 pA, Vec3 pB)
{
	Vec3 result;

	result.x = (pA.y * pB.z) - (pA.z * pB.y);
	result.y = (pA.z * pB.x) - (pA.x * pB.z);
	result.z = (pA.x * pB.y) - (pA.y * pB.x);

	return result;
}


Vec3 ScaleVector3(Vec3 pVector, float pScale)
{
	Vec3 result = pVector;

	result.x *= pScale;
	result.y *= pScale;
	result.z *= pScale;

	return result;
}


Vec3 AddVector3(Vec3 pA, Vec3 pB)
{
	Vec3 result;

	result.x = pA.x + pB.x;
	result.y = pA.y + pB.y;
	result.z = pA.z + pB.z;

	return result;
}

Vec3 SubtractVector3(Vec3 pA, Vec3 pB)
{
	Vec3 result;

	result.x = pA.x - pB.x;
	result.y = pA.y - pB.y;
	result.z = pA.z - pB.z;

	return result;
}