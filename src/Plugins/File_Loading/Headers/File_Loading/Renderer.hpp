#ifndef FILE_LOADING_RENDERER_HPP
#define FILE_LOADING_RENDERER_HPP

extern "C"
{
	#include <System/System.h>
	
	Shader* PLUGIN_LoadShader(void** pArgs);

	Model* PLUGIN_LoadModel(void** pArgs);
}

#endif