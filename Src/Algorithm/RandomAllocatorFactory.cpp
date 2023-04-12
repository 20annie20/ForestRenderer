#pragma once
#include "Common.h"
#include "RandomAllocatorFactory.h"
#include "RandomAllocator.h"

AllocatorAlgorithm* RandomAllocatorFactory::CreateAllocator() const
{
	return new RandomAllocator();
}