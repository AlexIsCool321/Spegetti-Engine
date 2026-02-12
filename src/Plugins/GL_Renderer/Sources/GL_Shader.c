#include <GL_Renderer/GL_Shader.h>

#include <stdio.h>
#include <stdlib.h>

unsigned short* PLUGIN_CreateShader(void** args)
{
	const char* vertex_shader;
	const char* fragment_shader;

	{
		if (!args[0]) printf("ERROR [PLUGIN] : VERTEX SHADER IS NULL!\n");
		if (!args[1]) printf("ERROR [PLUGIN] : FRAGMENT SHADER IS NULL!\n");

		if (!args[0] || !args[1]) return 0;

		vertex_shader	= args[0];
		fragment_shader	= args[1];
	}

	unsigned short* result = (unsigned short*)malloc(sizeof(unsigned short));

	*result = 1;

	return result;
}
