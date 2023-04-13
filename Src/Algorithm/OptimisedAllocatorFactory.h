#pragma once
#include "Common.h"
#include "AllocatorFactory.h"

/// Optimised allocator algorithm factory - implements allocator factory interface
/** Concrete factory that creates objects of the OptimisedAllocator type */
class OptimisedAllocatorFactory : public AllocatorFactory
{
public:
	/**
	* \brief Creates an instance of an optimised tree allocator.
	*/
	AllocatorAlgorithm* CreateAllocator() const override;
};