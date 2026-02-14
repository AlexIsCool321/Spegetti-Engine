#ifndef SYSTEM_IWINDOW_H
#define SYSTEM_IWINDOW_H

#include <stdint.h>

typedef struct
{

} IWindow;


IWindow* CreateWindow(unsigned int width, unsigned int height, const char* title);

void UpdateWindow(IWindow* window);
uint8_t IsWindowOpen(IWindow* window);

void DestroyWindow(IWindow* window);

#endif