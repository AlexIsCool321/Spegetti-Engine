#include <Math/DegRad.h>

#include <math.h>

float DegToRad(float pDegree)
{
	return pDegree * (M_PI / 180);
}

float RadToDef(float pRadiant)
{
	return pRadiant/(M_PI/180);
}