#ifndef RENDERER_LOADPROCADDRESS_H
#define RENDERER_LOADPROCADDRESS_H

typedef struct
{
	void* m_address;
} LoadProcAddress;

LoadProcAddress* CreateAddress(void* pAddress);
void DestroyAddress(LoadProcAddress* pProcAddress);

#endif