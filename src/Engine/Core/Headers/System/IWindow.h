#ifndef SYSTEM_IWINDOW_H
#define SYSTEM_IWINDOW_H

#include <stdint.h>

typedef struct
{

} IWindow;


IWindow* CreateWindow(unsigned int pWidth, unsigned int pHeight, const char* pTitle);

void UpdateWindow(IWindow* pWindow);
void SwapWindowBuffers(IWindow* pWindow);

uint8_t IsWindowOpen(IWindow* pWindow);

void* GetWindowProcedureAddress(IWindow* pWindow);

void DestroyWindow(IWindow* pWindow);

#endif