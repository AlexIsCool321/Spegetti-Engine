#ifndef SYSTEM_SEARCHPATH_H
#define SYSTEM_SEARCHPATH_H

#include <stdint.h>

#define MAX_SEARCHPATHES 16

extern const char* SearchPathes[MAX_SEARCHPATHES];
extern uint8_t SearchPathIndex;

void AddSearchPath(const char* pPath);

const char* ReadFile(const char* pFile);

void ClearSearchPathes();

#endif