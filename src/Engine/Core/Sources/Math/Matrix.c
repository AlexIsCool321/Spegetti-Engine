#include <Math/Matrix.h>

#include <stdio.h>
#include <stdlib.h>

Matrix CreateEmptyMatrix()
{
	Matrix result;

	result.m_values = (float*)malloc(sizeof(float) * 16);
	for (uint8_t i = 0; i < 16; i++)
	{
		result.m_values[i] = 0;
	}

	result.m_values[0]	= 1;
	result.m_values[5]	= 1;
	result.m_values[10]	= 1;
	result.m_values[15]	= 1;

	return result;
}


float GetMatrixValue(Matrix pMatrix, uint8_t pRow, uint8_t pCollum)
{
	return pMatrix.m_values[(pCollum * 4) + pRow];
}

void SetMatrixValue(Matrix pMatrix, uint8_t pRow, uint8_t pCollum, float pValue)
{
	pMatrix.m_values[(pCollum * 4) + pRow] = pValue;
}


Matrix MultiplyMatricies(Matrix pA, Matrix pB)
{
	Matrix result = CreateEmptyMatrix();

	for (uint8_t c = 0; c < 4; c++)
	{
		for (uint8_t r = 0; r < 4; r++)
		{
			float value;
			for (uint8_t i = 0; i < 4; i++)
			{
				value += GetMatrixValue(pA, r, i) * GetMatrixValue(pB, i, c);
			}

			SetMatrixValue(result, r, c, value);
		}
	}
}