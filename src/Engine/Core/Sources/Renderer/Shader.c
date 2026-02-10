#include <Renderer/Shader.h>

#include <PlugNPlay/PlugNPlay.h>

#include <string.h>

unsigned short CreateShader(const char* vertex_shader, const char* framgment_shader)
{
	void* args[2] =
	{
		&vertex_shader, &framgment_shader
	};

	return *(unsigned short*)CallPlugInFunction("PLUGIN_CreateShader", args);
}