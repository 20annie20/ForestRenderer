#pragma once
#include "GrowthSimulator.h"

GrowthSimulator::GrowthSimulator(std::vector<Tree> treeList, Terrain terrain)
{
	this->treeList = treeList;
	this->terrain = terrain;
}

std::span<std::pair<Point, Point>> GrowthSimulator::Grow()
{
	ve.clear();
	ve.push_back({Point(200, 100, 200, ColorType::Green), Point(200, 300, 200, ColorType::Green) });
	return ve;
}