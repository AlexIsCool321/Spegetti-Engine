#include <MGL_Renderer/Texture.h>

#include <glad/gl.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void* PLUGIN_CreateTexture(void** pArgs)
{
	unsigned int pWidth;
	unsigned int pHeight;
	unsigned char* pData;
	FILTER_MODE pFilterMode;
	REPEAT_MODE pRepeatMode;
	COLOR_RANGE pColorRange;

	{
		if (!pArgs[0]) printf("ERROR [PLGUIN] : WIDTH IS NULL!\n");
		if (!pArgs[1]) printf("ERROR [PLGUIN] : HEIGHT IS NULL!\n");
		if (!pArgs[3]) printf("ERROR [PLGUIN] : FILTER MODE IS NULL!\n");
		if (!pArgs[4]) printf("ERROR [PLGUIN] : REPEAT MODE IS NULL!\n");
		if (!pArgs[5]) printf("ERROR [PLGUIN] : COLOR RANGE IS NULL!\n");

		if (!pArgs[0] || !pArgs[1] || !pArgs[3]) return NULL;

		pWidth		=	*(unsigned int*)	pArgs[0];
		pHeight		=	*(unsigned int*)	pArgs[1];
		pData		=	 (unsigned char*)	pArgs[2];
		pFilterMode	=	*(FILTER_MODE*)		pArgs[3];
		pRepeatMode	=	*(REPEAT_MODE*)		pArgs[4];
		pColorRange	=	*(COLOR_RANGE*)		pArgs[5];
	}

	if (!pData)
	{
		printf("ERROR : TEXTURE DATA IS NULL!\n");
		
		pWidth	= 2;
		pHeight	= 2;

		unsigned char newData[12] =
		{
			200,	20,	150,
			0,		0,	0,
			0,		0,	0,
			200,	20,	150
		};

		pData = newData;

		pFilterMode = NEAREST;
		pRepeatMode = REPEAT;
		pColorRange = RGB;

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	}

	MGL_Texture* texture = (MGL_Texture*)malloc(sizeof(MGL_Texture));
	if (!texture)
	{
		printf("ERROR : FAIELD TO ALLOCATE MEMORY FOR TEXTURE!");
		return NULL;
	}

	GLint minFilter;
	GLint magFilter;
	switch (pFilterMode)
	{
		case NEAREST:
			minFilter = GL_LINEAR_MIPMAP_NEAREST;
			magFilter = GL_NEAREST;
			break;
		case LINEAR:
			minFilter = GL_LINEAR_MIPMAP_LINEAR;
			magFilter = GL_LINEAR;
			break;

		default:
			minFilter = GL_LINEAR_MIPMAP_LINEAR;
			magFilter = GL_LINEAR;
			break;
	}

	GLint repeatMode;
	switch (pRepeatMode)
	{
		case REPEAT:
			repeatMode = GL_REPEAT;
			break;
		case MIRROR:
			repeatMode = GL_MIRRORED_REPEAT;
			break;
		case CLAMP_TO_EDGE:
			repeatMode = GL_CLAMP_TO_EDGE;
			break;
		case CLAMP_TO_BORDER:
			repeatMode = GL_CLAMP_TO_BORDER;
			break;

		default:
			repeatMode = GL_REPEAT;
			break;
	}

	GLint colorRange;
	switch (pColorRange)
	{
		case RED:
			colorRange = GL_RED;
			break;
		case RG:
			colorRange = GL_RG;
			break;
		case RGB:
			colorRange = GL_RGB;
			break;
		case RGBA:
			colorRange = GL_RGBA;
			break;
		
		default:
			colorRange = GL_RGB;
			break;
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, repeatMode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, repeatMode);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);


	glGenTextures(1, &texture->id);
	glBindTexture(GL_TEXTURE_2D, texture->id);

	glTexImage2D(GL_TEXTURE_2D, 0, colorRange, pWidth, pHeight, 0, colorRange, GL_UNSIGNED_BYTE, pData);
	glGenerateMipmap(GL_TEXTURE_2D);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 0);

	return texture;
}


void PLUGIN_BindTexture(void** pArgs)
{
	MGL_Texture* pTexture;

	{
		if (!pArgs[0]) printf("ERROR : TEXTURE IS NULL!\n");

		if (!pArgs[0]) return;

		pTexture = (MGL_Texture*)pArgs[0];
	}

	glActiveTexture(GL_TEXTURE0 + pTexture->id);
	glBindTexture(GL_TEXTURE_2D, pTexture->id);
}

void PLUGIN_UnbindTexture(void** pArgs)
{
	MGL_Texture* pTexture;

	{
		if (!pArgs[0]) printf("ERROR : TEXTURE IS NULL!\n");

		if (!pArgs[0]) return;

		pTexture = (MGL_Texture*)pArgs[0];
	}

	glActiveTexture(GL_TEXTURE0 + pTexture->id);
	glBindTexture(GL_TEXTURE_2D, 0);
}


void PLUGIN_DestroyTexture(void** pArgs)
{
	MGL_Texture* pTexture;

	{
		if (!pArgs[0]) printf("WARN : Texture is already NULL!\n");

		if (!pArgs[0]) return;

		pTexture = (MGL_Texture*)pArgs[0];
	}

	glDeleteTextures(1, &pTexture->id);
	free(pArgs[0]);
}