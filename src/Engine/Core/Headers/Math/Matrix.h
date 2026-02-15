#ifndef MATH_MATRIX_H
#define MATH_MATRIX_H

#include <stdint.h>

/*
 * 0	4	8	12
 * 1	5	9	13
 * 2	6	10	14
 * 3	7	11	15
*/

typedef struct
{
	float* m_values;
} Matrix;

Matrix CreateEmptyMatrix();

float GetMatrixValue(Matrix pMatrix, uint8_t pRow, uint8_t pCollum);
void SetMatrixValue(Matrix pMatrix, uint8_t pRow, uint8_t pCollum, float pValue);

Matrix MultiplyMatricies(Matrix pA, Matrix pB);

#endif