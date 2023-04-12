#pragma once
#include "Common.h"
#include "AllocatorFactory.h"

class RandomAllocatorFactory : public AllocatorFactory
{
public:
	AllocatorAlgorithm* CreateAllocator() const override;
};