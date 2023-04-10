#pragma once
#include "Engine.h"

#define MAX_TICKS 10000

Engine::Engine()
{
	gui = new GUI();
	renderer = new SDLRenderer();
	
	// debug
	for (int i = 0; i < 60; i++)
	{
		treeVector.push_back(Tree(Species_ID::PINE));
	}
	for (int i = 0; i < 40; i++)
	{
		treeVector.push_back(Tree(Species_ID::MAPLE));
	}
	for (int i = 0; i < 60; i++)
	{
		treeVector.push_back(Tree(Species_ID::OAK));
	}
}

void Engine::Init(AllocatorType allocType)
{
	switch (allocType)
	{
	case Random:
		allocator = new RandomAllocator();
		break;
	default:
		allocator = new RandomAllocator();
		break;
	}
	terrain = new Terrain();
}

Engine::~Engine()
{
	Cleanup();
	delete renderer;
}

void Engine::Run(bool growIndependently)
{
	Point range = Point(255, 400, 255);
	renderer->DrawPoints(terrain->GetPoints<ColoredPoint>(), range);

	allocator->Allocate(treeVector, *terrain);

	// TODO: grow dependently
	simulator = GrowthSimulator(treeVector);

	bool doQuit = false;
	uint64_t iterations = 0;
	std::vector<std::pair<ColoredPoint, ColoredPoint>> Lines;
	while (!doQuit)
	{
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT || (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE))
				doQuit = true;
			break;
		}


		if (iterations++ < MAX_TICKS) {
			//while not stop event
			Lines = simulator.Grow();
		}

		renderer->DrawEdges(Lines, range);
		renderer->DrawGUI(*gui);
		const auto ms = timer.Mark(); // ms counter to display
		renderer->Present();
	}
}

void Engine::Cleanup()
{
	delete allocator;
	delete terrain;
}