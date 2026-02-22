#ifndef MGL_RENDERER_TEXTURE_H
#define MGL_RENDERER_TEXTURE_H

#include <Renderer/Texture.h>

typedef struct
{
	Texture base;

	unsigned int id;
} MGL_Texture;

void* PLUGIN_CreateTexture(void** pArgs);

void PLUGIN_BindTexture(void** pArgs);
void PLUGIN_UnbindTexture(void** pArgs);

void PLUGIN_DestroyTexture(void** pArgs);

#endif