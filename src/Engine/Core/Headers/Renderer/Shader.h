#ifndef RENDERER_SHADER_H
#define RENDERER_SHADER_H

#include <Renderer/Texture.h>

#include <stdint.h>

typedef struct
{

} Shader;

Shader* CreateShader(const char* pVertex, const char* pFragment);

void SetTextureUniform(Shader* pShader, const char* pName, Texture* pTexture);

#endif