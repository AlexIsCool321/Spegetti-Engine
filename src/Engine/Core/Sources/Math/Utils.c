#include <Math/Utils.h>

#include <math.h>

float ClampFloat(float pValue, float pMin, float pMax)
{
	if (pValue > pMax)
	{
		return pMax;
	}
	else if (pValue < pMin)
	{
		return pMin;
	}
	
	return pValue;
}

float DegToRad(float pDegree)
{
	return pDegree * (M_PI / 180);
}

float RadToDeg(float pRadiant)
{
	return pRadiant/(M_PI/180);
}