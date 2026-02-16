#include <System/Renderer.h>

#include <Renderer/Shader.h>

#include <System/SearchPath.h>

#include <stdio.h>

unsigned int LoadShader(const char* pType)
{
	const char* vertex;
	const char* fragment;

	char path[512];

	sprintf(path, "shaders/%s.vs", pType);
	vertex = ReadFile(path);
	if (!vertex)
	{
		printf("ERROR : FAILED TO READ VERTEX FILE!\n");
		return 0;
	}

	sprintf(path, "shaders/%s.fs", pType);
	fragment = ReadFile(path);
	if (!fragment)
	{
		printf("ERROR : FAILED TO READ FRAGMENT FILE!\n");
		return 0;
	}

	return CreateShader(vertex, fragment);
}