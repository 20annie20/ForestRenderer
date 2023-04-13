#pragma once
#include "Common.h"
#include "AllocatorFactory.h"

/// Random allocator algorithm factory - implements allocator factory interface
/** Concrete factory that creates objects of the RandomAllocator type */
class RandomAllocatorFactory : public AllocatorFactory
{
public:
	AllocatorAlgorithm* CreateAllocator() const override;
};