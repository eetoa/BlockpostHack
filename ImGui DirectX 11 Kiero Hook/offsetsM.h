#pragma once
#include "includes.h"
#include <vector>

class offsetsM
{
public:
	DWORD GetPointerAddress(DWORD ptr, std::vector<DWORD> offsets);
};