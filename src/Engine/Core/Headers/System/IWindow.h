#ifndef SYSTEM_IWINDOW_H
#define SYSTEM_IWINDOW_H

#include <stdint.h>

#include <Math/Vec2.h>

typedef struct
{

} IWindow;


IWindow* CreateWindow(unsigned int pWidth, unsigned int pHeight, const char* pTitle);

void UpdateWindow(IWindow* pWindow);
void SwapWindowBuffers(IWindow* pWindow);

uint8_t IsWindowOpen(IWindow* pWindow);
Vec2 GetWindowSize(IWindow* pWindow);

void* GetWindowProcedureAddress(IWindow* pWindow);

void DestroyWindow(IWindow* pWindow);

#endif