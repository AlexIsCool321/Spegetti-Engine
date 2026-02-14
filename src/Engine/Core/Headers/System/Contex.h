#ifndef SYSTEM_CONTEX_H
#define SYSTEM_CONTEX_H

#include <System/IWindow.h>
#include <Renderer/Surface.h>

void AttachSurfaceToWindow(IWindow* pWindow, Surface* pSurface);

#endif