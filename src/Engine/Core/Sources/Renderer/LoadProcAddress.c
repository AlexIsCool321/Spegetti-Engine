#include <Renderer/LoadProcAddress.h>

#include <stdio.h>
#include <stdlib.h>

LoadProcAddress* CreateAddress(void* pAddress)
{
	{
		if (!pAddress) printf("ERROR : ADDRESS IS NULL!\n");

		if (!pAddress) return NULL;
	}

	LoadProcAddress* result = (LoadProcAddress*)malloc(sizeof(LoadProcAddress));
	result->m_address = pAddress;

	return result;
}

void DestroyAddress(LoadProcAddress* pProcAddress)
{
	{
		if (!pProcAddress) printf("WARN : Procuder address is already NULL.\n");

		if (!pProcAddress) return;
	}

	free(pProcAddress->m_address);
	free(pProcAddress);
}