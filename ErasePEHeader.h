#pragma once
#include <Windows.h>

class ErasePeHeader
{
public:
	__forceinline bool ErasePeHeaderx86()
	{
		DWORD dwOldProtect;
		char* chrBaseAddress = (char*)GetModuleHandle(NULL);

		if (!VirtualProtect(chrBaseAddress, 4096, PAGE_READWRITE, &dwOldProtect))
			return false;

		SecureZeroMemory(chrBaseAddress, 4096);
		return true;
	}

private:

protected:

};

extern ErasePeHeader g_EraseHeaders;