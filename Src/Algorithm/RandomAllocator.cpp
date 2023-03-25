#pragma once
#include "RandomAllocator.h"

void RandomAllocator::setTreeList(std::vector<Tree> treeList)
{
	treeList = treeList;
}

void RandomAllocator::setTerrain(Terrain terrain)
{
	terrain = terrain;
}

std::span<Point> RandomAllocator::allocate()
{
	std::span<Point> pp;
	return pp;
}