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
	treeVector.push_back(Tree(Tree::Species::Oak));
}

Engine::~Engine()
{
	delete renderer;
	delete allocator;
}

void Engine::run(AllocatorType allocType)
{
	Point range = Point(255, 400, 255);
	renderer->drawPoints(terrain.getPoints(), range);
	switch (allocType)
	{
		case Random:
			allocator = new RandomAllocator();
			break;
		default:
			allocator = new RandomAllocator();
			break;
	}
	
	allocator->setTerrain(terrain);
	allocator->setTreeList(treeVector);
	renderer->drawPoints(allocator->allocate(), range);
	
	// renderer->Run(); // to show the animation
}

void Engine::cleanup()
{
}