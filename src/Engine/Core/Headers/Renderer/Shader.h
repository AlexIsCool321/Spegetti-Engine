#ifndef RENDERER_SHADER_H
#define RENDERER_SHADER_H

#include <Renderer/Texture.h>

#include <stdint.h>

unsigned int CreateShader(const char* pVertex, const char* pFragment);

void SetTextureUniform(unsigned int pShader, const char* pName, Texture* pTexture);

#endif