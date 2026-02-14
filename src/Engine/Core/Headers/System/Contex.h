#ifndef SYSTEM_CONTEX_H
#define SYSTEM_CONTEX_H

#include <System/IWindow.h>

#include <Renderer/Surface.h>
#include <Renderer/Instance.h>

void AttachSurfaceAndInstanceToWindow(IWindow* pWindow, Surface* pSurface, Instance* pInstace);
#endif