#include <Math/Vec3.h>
#include <Math/Vec2.h>

#include <glad/gl.h>

#include <stdio.h>

void PLUGIN_ClearScreen(void** pArgs)
{
	Vec3 pColor;

	{
		if (!pArgs[0]) printf("ERROR [PLUGIN] : CLEAR COLOR IS NULL!\n");

		if (!pArgs[0]) return;

		pColor = *(Vec3*)pArgs[0];
	}

	glClearColor(pColor.x, pColor.y, pColor.z, 0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void PLUGIN_ResizeScreen(void** pArgs)
{
	Vec2 pSize;

	{
		if (!pArgs[0]) printf("ERROR [PLUGIN] : CLEAR COLOR IS NULL!\n");

		if (!pArgs[0]) return;

		pSize = *(Vec2*)pArgs[0];
	}

	glViewport(0, 0, pSize.x, pSize.y);
}