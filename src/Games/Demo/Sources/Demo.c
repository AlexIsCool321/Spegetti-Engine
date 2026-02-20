#include <Demo/Demo.h>

#include <stdio.h>

void GameInit()
{
	printf("Hello World From Demo!\n");

	Model* model = LoadModel("cube", "obj");
}