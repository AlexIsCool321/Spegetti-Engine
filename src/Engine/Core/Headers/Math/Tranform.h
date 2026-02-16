#ifndef MATH_TRANSFORM_H
#define MATH_TRANSFORM_H

#include <Math/Matrix.h>
#include <Math/Vec3.h>

Matrix CreateTransform(Vec3 pPosition, Vec3 pRotation, Vec3 pScale);

Matrix LookAtMatrix(Vec3 pEye, Vec3 pTarget);

#endif