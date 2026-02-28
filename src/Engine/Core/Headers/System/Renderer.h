#ifndef SYSTEM_RENDERER_H
#define SYSTEM_RENDERER_H

#include <Renderer/Renderer.h>

Shader* LoadShader(const char* pType);

Model* LoadModel(const char* pName, const char* pFormat);

#endif