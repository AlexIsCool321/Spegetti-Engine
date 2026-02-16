#ifndef SYSTEM_INPUT_H
#define SYSTEM_INPUT_H

#include <System/IWindow.h>
#include <System/Key.h>

#include <stdint.h>

uint8_t IsKeyPressed(IWindow* pWindow, KEY pKey);

#endif