#pragma once
#include "Common.h"
#include "AllocatorAlgorithm.h"

/// Abstract allocator algorithm factory interface
/** Interface of a factory that creates different types of Allocators */
class AllocatorFactory
{
public:
	/**
	* \brief Creates an instance of a tree allocator.
	*/
	virtual AllocatorAlgorithm *CreateAllocator() const = 0;
};