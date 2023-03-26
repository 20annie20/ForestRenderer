#pragma once
#include "Engine.h"

#define MAX_TICKS 10000

Engine::Engine()
{
	renderer = new SDLRenderer();
	allocator = new RandomAllocator();
	
	// debug
	for (int i = 0; i < 60; i++)
	{
		treeVector.push_back(Tree(Species_ID::PINE));
	}
	for (int i = 0; i < 40; i++)
	{
		treeVector.push_back(Tree(Species_ID::MAPLE));
	}
	for (int i = 0; i < 20; i++)
	{
		treeVector.push_back(Tree(Species_ID::OAK));
	}
}

Engine::~Engine()
{
	delete renderer;
	delete allocator;
}

void Engine::Run(AllocatorType allocType)
{
	Point range = Point(255, 400, 255);
	renderer->DrawPoints(terrain.GetPoints<ColoredPoint>(), range);

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
	uint64_t iterations = 0;
	while (!doQuit)
	{
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT || (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE))
				doQuit = true;
			break;
		}
		while (iterations++ != MAX_TICKS) {
			//while not stop event
			std::vector<std::pair<Point, Point>> Lines = simulator.Grow();

			std::vector<std::pair<ColoredPoint, ColoredPoint>> ColoredLines(Lines.size());
			std::transform(Lines.begin(), Lines.end(), ColoredLines.begin(),
				[](std::pair<Point, Point> pair) {
					return std::pair(
						ColoredPoint(pair.first.x, pair.first.y, pair.first.z, Green),
						ColoredPoint(pair.second.x, pair.second.y, pair.second.z, Green));
				});

			renderer->DrawEdges(ColoredLines, range);
			const auto ms = timer.Mark(); // ms counter to display
		}
	}
}

void Engine::Cleanup()
{
}