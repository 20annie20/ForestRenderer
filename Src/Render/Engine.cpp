#pragma once
#include "Engine.h"

Engine::Engine()
{
	renderer = new SDLRenderer();
	allocator = new RandomAllocator();
	
	// debug
	treeVector.push_back(Tree(Species_ID::PINE));
	treeVector.push_back(Tree(Species_ID::PINE));
	treeVector.push_back(Tree(Species_ID::PINE));
	treeVector.push_back(Tree(Species_ID::PINE));
	treeVector.push_back(Tree(Species_ID::PINE));
	treeVector.push_back(Tree(Species_ID::PINE));
	treeVector.push_back(Tree(Species_ID::PINE));
	treeVector.push_back(Tree(Species_ID::PINE));
	treeVector.push_back(Tree(Species_ID::PINE));
	treeVector.push_back(Tree(Species_ID::PINE));
	treeVector.push_back(Tree(Species_ID::OAK));
	treeVector.push_back(Tree(Species_ID::OAK));
	treeVector.push_back(Tree(Species_ID::OAK));
	treeVector.push_back(Tree(Species_ID::OAK));
	treeVector.push_back(Tree(Species_ID::OAK));
	treeVector.push_back(Tree(Species_ID::OAK));
	treeVector.push_back(Tree(Species_ID::OAK));
	treeVector.push_back(Tree(Species_ID::OAK));
	treeVector.push_back(Tree(Species_ID::OAK));
	treeVector.push_back(Tree(Species_ID::OAK));
	treeVector.push_back(Tree(Species_ID::OAK));
	treeVector.push_back(Tree(Species_ID::OAK));
	treeVector.push_back(Tree(Species_ID::OAK));
	treeVector.push_back(Tree(Species_ID::OAK));
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
	allocator->Allocate(treeVector);

	simulator = GrowthSimulator(treeVector, terrain);
	bool doQuit = false;

	while (!doQuit)
	{
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT || (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE))
				doQuit = true;
			break;
		}

		//while not stop event
		std::span<std::pair<Point, Point>> Lines = simulator.Grow();
		renderer->DrawEdges(Lines, range);
		const auto ms = timer.Mark();
	}
}

void Engine::Cleanup()
{
}