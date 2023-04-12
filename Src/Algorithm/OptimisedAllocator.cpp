#pragma once
#include "OptimisedAllocator.h"

 void OptimisedAllocator::Allocate(std::vector<Tree>& treeList, Terrain& terrain)
{
	std::pair<int, int> mapSize = terrain.GetMapSize();

	const int range_fromX = 0.1 * mapSize.first; // first 10% of the terrain is left untouched
	const int range_toX = 0.9 * mapSize.first; // last 10% of the terrain is left untouched

	const int range_fromY = 0.1 * mapSize.second;
	const int range_toY = 0.9 * mapSize.second;

	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<int>  distrX(range_fromX, range_toX);
	std::uniform_int_distribution<int>  distrY(range_fromY, range_toY);

	for(auto& t : treeList)
	{

		t.SetLocation(distrX(generator), distrY(generator));
		Point p = t.GetLocation();
		p.y = terrain.GetHeight(p.x, p.z);
		t.SetLocation(p);
	}
}