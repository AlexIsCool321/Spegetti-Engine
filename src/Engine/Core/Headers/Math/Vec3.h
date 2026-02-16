#ifndef MATH_VEC3_H
#define MATH_VEC3_H

typedef struct
{
	float x;
	float y;
	float z;
} Vec3;

Vec3 Vector3(float pX, float pY, float pZ);

Vec3 Normalized(Vec3 pVector);
Vec3 CrossVector3(Vec3 pA, Vec3 pB);

Vec3 AddVector3(Vec3 pA, Vec3 pB);
Vec3 SubtractVector3(Vec3 pA, Vec3 pB);

#endif