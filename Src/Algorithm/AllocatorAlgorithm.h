#pragma once
#include "Common.h"
#include "Tree.h"
#include "Terrain.h"

enum AllocatorType
{
	Random,
	Cluster
};

class AllocatorAlgorithm
{
protected:
	std::vector<Tree> treeList;
	Terrain terrain;
	std::vector<Point> allocationPoints;

public:
	virtual void SetTreeList(std::vector<Tree> treeList) = 0;
	virtual	void SetTerrain(Terrain terrain) = 0;
	virtual	std::span<Point> Allocate() = 0;
};