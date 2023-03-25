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
	std::vector<Tree>* treeList; // reference to objects needed to generate placements
	Terrain* terrain = new Terrain();

public:
	virtual void setTreeList(std::vector<Tree> treeList) = 0;
	virtual	void setTerrain(Terrain terrain) = 0;
	virtual	std::span<Point> allocate() = 0;
};