#include <Renderer/Shader.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>
#include <string.h>

unsigned short CreateShader(const char* vertex_shader, const char* framgment_shader)
{
	{
		if (!vertex_shader) printf("ERROR : VERTEX SHADER IS NULL!\n");
		if (!framgment_shader) printf("ERROR : FRAGMENT SHADER IS NULL!\n");

		if (!vertex_shader || !framgment_shader) return 0;
	}

	void* args[2] =
	{
		&vertex_shader, &framgment_shader
	};

	unsigned short* result = (unsigned short*)CallPlugInFunction("PLUGIN_CreateShader", args);
	if (!result)
	{
		printf("ERROR : FAILED TO CREATE SHADER!\n");
		return 0;
	}

	return *result;
}