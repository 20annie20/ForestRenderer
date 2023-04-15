#pragma once
#include "OptimisedAllocator.h"
#include <math.h>

void OptimisedAllocator::FindCentroids(std::unordered_map<Species_ID, int>& tm, std::vector<Tree>& treeList, std::pair<int, int> mapSize)
{
	for (auto& i : tm)
	{
		int minX = mapSize.first, minZ = mapSize.first, maxX = 0, maxZ = 0;
		for (int it = 0; it < i.second; it++)
		{
			if (treeList[it].GetLocation().x > maxX) 
			{
				maxX = treeList[it].GetLocation().x;
			}
			if (treeList[it].GetLocation().x < minX) 
			{
				minX = treeList[it].GetLocation().x;
			}
			if (treeList[it].GetLocation().z > maxX) 
			{
				maxZ = treeList[it].GetLocation().z;
			}
			if (treeList[it].GetLocation().z < minX) 
			{
				minZ = treeList[it].GetLocation().z;
			}
		}
		std::random_device                  rand_dev;
		std::mt19937                        generator(rand_dev());

		if (maxZ < minZ)
			maxZ = minZ;
		if (maxX < minX)
			maxX = minX;

		std::uniform_int_distribution<int>  distrX(minX, maxX);
		std::uniform_int_distribution<int>  distrZ(minZ, maxZ);
		centroids[i.first] = Point(distrX(generator), 0, distrZ(generator));
	}
}


void OptimisedAllocator::Allocate(std::unordered_map<Species_ID, int>& tm,std::vector<Tree>& treeList, Terrain& terrain)
{
	std::pair<int, int> mapSize = terrain.GetMapSize();

	const int range_fromX = 0;
	const int range_toX = mapSize.first;

	const int range_fromZ = 0;
	const int range_toZ = mapSize.second;

	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<int>  distrX(range_fromX, range_toX);
	std::uniform_int_distribution<int>  distrY(range_fromZ, range_toZ);
	for (auto& t : treeList)
	{

		t.SetLocation(distrX(generator), distrY(generator));
		Point p = t.GetLocation();
		p.y = terrain.GetHeight(p.x, p.z);
		t.SetLocation(p);
	}

	FindCentroids(tm, treeList, mapSize);

	float step = 10;
	for(auto& t : treeList)
	{
		for (int i = 0; i < 30; i++)
		{

			Point a = t.GetLocation();
			Point b = centroids[t.species];

			auto xDiff = b.x - a.x;
			auto zDiff = b.z - a.z;

			auto distance = sqrt(zDiff * zDiff + xDiff * xDiff);
			auto xUnit = xDiff / distance;
			auto zUnit = zDiff / distance;
			if (xUnit < 1)
				xUnit = 1;
			if (xUnit < 1)
				xUnit = 1;

			int newX = t.GetLocation().x + xUnit * step;
			int newZ = t.GetLocation().z + zUnit * step;
			if (newX >= 0 && newX < range_toX && newZ >= 0 && newZ < range_toZ)
			{
				int newY = terrain.GetHeight(newX, newZ);
				t.SetLocation(Point(newX, newY, newZ));
			}
		}
	}
}