#ifndef SYSTEM_IWINDOW_H
#define SYSTEM_IWINDOW_H

#include <stdint.h>

#include <Renderer/LoadProcAddress.h>

typedef struct
{
	uint8_t m_open;
} IWindow;


IWindow* CreateWindow(unsigned int width, unsigned int height, const char* title);

LoadProcAddress* GetWindowLoadProcAddress(IWindow* window);

void UpdateWindow(IWindow* window);
void SwapWindowBuffers(IWindow* window);

uint8_t IsWindowOpen(IWindow* window);

void DestroyWindow(IWindow* window);

#endif