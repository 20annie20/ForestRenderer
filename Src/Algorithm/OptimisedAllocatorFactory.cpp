#pragma once
#include "Common.h"
#include "OptimisedAllocatorFactory.h"
#include "OptimisedAllocator.h"

AllocatorAlgorithm* OptimisedAllocatorFactory::CreateAllocator() const
{
	return new OptimisedAllocator();
}