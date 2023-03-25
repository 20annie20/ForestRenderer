#pragma once
#include "Engine.h"

Engine::Engine()
{
	renderer = new SDLRenderer();
	allocator = new RandomAllocator();
	// input Observer?
	// 
	// debug
	treeVector.push_back(Tree(Tree::Species::Pine));
	treeVector.push_back(Tree(Tree::Species::Pine));
	treeVector.push_back(Tree(Tree::Species::Pine));
	treeVector.push_back(Tree(Tree::Species::Pine));
	treeVector.push_back(Tree(Tree::Species::Pine));
	treeVector.push_back(Tree(Tree::Species::Pine));
	treeVector.push_back(Tree(Tree::Species::Pine));
	treeVector.push_back(Tree(Tree::Species::Pine));
	treeVector.push_back(Tree(Tree::Species::Pine));
	treeVector.push_back(Tree(Tree::Species::Pine));
	treeVector.push_back(Tree(Tree::Species::Pine));
	treeVector.push_back(Tree(Tree::Species::Pine));
	treeVector.push_back(Tree(Tree::Species::Pine));
	treeVector.push_back(Tree(Tree::Species::Pine));
	treeVector.push_back(Tree(Tree::Species::Pine));
	treeVector.push_back(Tree(Tree::Species::Oak));
	treeVector.push_back(Tree(Tree::Species::Oak));
	treeVector.push_back(Tree(Tree::Species::Oak));
	treeVector.push_back(Tree(Tree::Species::Oak));
	treeVector.push_back(Tree(Tree::Species::Oak));
	treeVector.push_back(Tree(Tree::Species::Oak));
	treeVector.push_back(Tree(Tree::Species::Oak));
	treeVector.push_back(Tree(Tree::Species::Oak));
	treeVector.push_back(Tree(Tree::Species::Oak));
	treeVector.push_back(Tree(Tree::Species::Oak));
	treeVector.push_back(Tree(Tree::Species::Oak));
	treeVector.push_back(Tree(Tree::Species::Oak));
	treeVector.push_back(Tree(Tree::Species::Oak));
	treeVector.push_back(Tree(Tree::Species::Oak));
	treeVector.push_back(Tree(Tree::Species::Oak));
	treeVector.push_back(Tree(Tree::Species::Oak));
}

Engine::~Engine()
{
	delete renderer;
	delete allocator;
}

void Engine::Run(AllocatorType allocType)
{
	Point range = Point(255, 400, 255);
	renderer->DrawPoints(terrain.GetPoints(), range);
	switch (allocType)
	{
		case Random:
			allocator = new RandomAllocator();
			break;
		default:
			allocator = new RandomAllocator();
			break;
	}
	
	allocator->SetTerrain(terrain);
	allocator->SetTreeList(treeVector);
	std::span<Point> allocationPoints = allocator->Allocate();
	renderer->DrawPoints(allocationPoints, range);
	// renderer->Run(); // to show the animation
}

void Engine::Cleanup()
{
}