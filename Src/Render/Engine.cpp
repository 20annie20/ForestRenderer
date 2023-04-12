#pragma once
#include "Engine.h"
#include <chrono>
#include <thread>

#define MAX_TICKS 10000

Engine::Engine()
{
	gui = new GUI(*this);
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
	allocator->Allocate(treeVector, *terrain);

	// TODO: grow dependently
	simulator = GrowthSimulator(treeVector);

	bool doQuit = false;
	bool startedSim = false;
	uint64_t iterations = 0;
	float timeSinceLastGrow = 0;
	std::vector<std::pair<ColoredPoint, ColoredPoint>> lines;
	std::vector<ColoredPoint> points = terrain->GetPoints<ColoredPoint>();
	lines.reserve(2'000'000'000 / 16);
	while (!doQuit)
	{
		while (SDL_PollEvent(&event)) 
		{
			ImGui_ImplSDL2_ProcessEvent(&event);
			if (event.type == SDL_QUIT || (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE))
				doQuit = true;
			break;
		}
		renderer->Clear();

		if (state == EngineState::SETUP_MENU)
		{
			if (startedSim)
			{
				startedSim = false;
				allocator->Allocate(treeVector, *terrain);
				simulator = GrowthSimulator(treeVector);
				iterations = 0;
				timeSinceLastGrow = 0;
				lines.clear();
			}
			renderer->DrawGUI(*gui, &GUI::DrawStartupFrame);
		}

		else
		{
			startedSim = true;
			if (iterations < MAX_TICKS && timeSinceLastGrow > 0.01) {
				//while not stop event
				auto& newLines = simulator.Grow();
				lines.insert(lines.end(), newLines.begin(), newLines.end());
				timeSinceLastGrow = 0;
				iterations++;
			}
			Point range = Point(255, 400, 255);
			renderer->DrawPoints(points, range);
			renderer->DrawEdges(lines, range);
			const auto sec = timer.Mark(); // seconds counter to display FPS
			timeSinceLastGrow += sec;
			renderer->DrawGUI(*gui, &GUI::DrawFrame);
		}
		renderer->Present();
	}
}

void Engine::Cleanup()
{
	delete allocator;
	delete terrain;
}

void Engine::SetState(EngineState state)
{
	this->state = state;
}