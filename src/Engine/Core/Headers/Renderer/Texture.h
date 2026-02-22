#ifndef RENDERER_TEXTURE_H
#define RENDERER_TEXTURE_H

typedef struct
{

} Texture;


typedef enum
{
	REPEAT,
	MIRROR,
	CLAMP_TO_EDGE,
	CLAMP_TO_BORDER
} REPEAT_MODE;

typedef enum
{
	NEAREST,
	LINEAR
} FILTER_MODE;

typedef enum
{
	RED,
	RG,

	RGB,

	RGBA
} COLOR_RANGE;


Texture CreateTexture(unsigned int pWidth, unsigned int pHeight, unsigned char* pData, FILTER_MODE pFilterMode, REPEAT_MODE pRepeatMode, COLOR_RANGE pColorRange);

void BindTexture(Texture* pTexture);
void UnbindTexture(Texture* pTexture);

void DestroyTexture(Texture* pTexture);

#endif