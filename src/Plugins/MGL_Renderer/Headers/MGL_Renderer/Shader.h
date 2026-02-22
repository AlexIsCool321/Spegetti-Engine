#ifndef MGL_RENDERER_SHADER_H
#define MGL_RENDERER_SHADER_H

#include <Renderer/Shader.h>

typedef struct
{
	Shader base;

	unsigned int id;
} MGL_Shader;

void* PLUGIN_CreateShader(void** pArgs);

void PLUGIN_SetTextureUniform(void** pArgs);

#endif