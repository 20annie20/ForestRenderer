#pragma once
#include "Common.h"
#include "AllocatorAlgorithm.h"
#include <random>

/// Allocator of trees that optimise allocation with clustering
/** Allocator finds placement of each tree on the terrain surface. It first picks the placement randomly
but then find a random centroid for each species and moves tree towards it. 
Allocation points are to be used in growth simulation. */
class OptimisedAllocator : public AllocatorAlgorithm
{
	std::unordered_map<Species_ID, Point> centroids;
	void FindCentroids(std::unordered_map<Species_ID, int>& tm, std::vector<Tree>& treeList, std::pair<int, int> mapSize);
public:
	/**
	* \brief Asigns each tree a Point coordinate 
	* First it assings a random point using terrain height and width, length coordinates
	* Then for each tree species group, a random centroid is selected between their maximum and minimum width and length
	* coordinates and the trees are iteratively moved toward that centroid to create a cluster.
	* \param[in] tm tree map with amount of trees for each species
	* \param[out] treeList contains all trees with their location to set
	* \param[in] terrain is the terrain data with heights needed to set starting points of the trees
	*/
	void Allocate(std::unordered_map<Species_ID, int>& tm, std::vector<Tree>& treeList, Terrain& terrain);
};