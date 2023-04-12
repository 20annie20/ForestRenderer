#pragma once
#include "Common.h"
#include "AllocatorAlgorithm.h"

class AllocatorFactory
{
public:
	virtual AllocatorAlgorithm *CreateAllocator() const = 0;
};