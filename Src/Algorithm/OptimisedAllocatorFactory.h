#pragma once
#include "Common.h"
#include "AllocatorFactory.h"

class OptimisedAllocatorFactory : public AllocatorFactory
{
public:
	AllocatorAlgorithm* CreateAllocator() const override;
};