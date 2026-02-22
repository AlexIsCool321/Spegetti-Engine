#include <Renderer/Texture.h>

#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

Texture* CreateTexture(unsigned int pWidth, unsigned int pHeight, unsigned char* pData, FILTER_MODE pFilterMode, REPEAT_MODE pRepeatMode, COLOR_RANGE pColorRange)
{
	void* args[6] =
	{
		&pWidth,
		&pHeight,
		pData,
		&pFilterMode,
		&pRepeatMode,
		&pColorRange
	};

	Texture* result = (Texture*)CallPlugInFunction("PLUGIN_CreateTexture", args);
	if (!result)
	{
		printf("ERROR : [ PLUGIN_CreateTexture ] RETURNED NULL!\n");
		return NULL;
	}

	return result;
}


void BindTexture(Texture* pTexture)
{
	{
		if (!pTexture) printf("ERROR : TEXTURE IS NULL!\n");

		if (!pTexture) return;
	}

	void* args[1] =
	{
		pTexture
	};

	CallPlugInFunction("PLUGIN_BindTexture", args);
}

void UnbindTexture(Texture* pTexture)
{
	{
		if (!pTexture) printf("ERROR : TEXTURE IS NULL!\n");

		if (!pTexture) return;
	}

	void* args[1] =
	{
		pTexture
	};

	CallPlugInFunction("PLUGIN_UnbindTexture", args);
}


void DestroyTexture(Texture* pTexture)
{
	{
		if (!pTexture) printf("WARN : Texture is already NULL!\n");

		if (!pTexture) return;
	}

	void* args[1] =
	{
		pTexture
	};

	CallPlugInFunction("PLUGIN_DestroyTexture", args);

	free(pTexture);
}