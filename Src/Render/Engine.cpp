#pragma once
#include "Engine.h"
#include <chrono>
#include <thread>

#define MAX_TICKS 10000

Engine::Engine()
{
	gui = new GUI(*this);
	renderer = new SDLRenderer();
	
	for (const auto& i : allSpecies)
	{
		treesMap[i] = 0;
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
			if (startedSim) // clean up previous simulation data
			{
				startedSim = false;
				iterations = 0;
				timeSinceLastGrow = 0;
				lines.clear();
				treeVector.clear();
			}
			renderer->DrawGUI(*gui, &GUI::DrawStartupFrame);
		}

		else
		{
			if (!startedSim)
			{
				for (const auto& i : treesMap)
				{
					for (auto j = 0; j < i.second; j++)
					{
						treeVector.push_back(Tree(i.first));
					}
				}
				startedSim = true;
				allocator->Allocate(treeVector, *terrain);
				simulator = GrowthSimulator(treeVector);
			}
			
			if (iterations < MAX_TICKS && timeSinceLastGrow > 0.001) {
				//while not stop event
				auto& newLines = simulator.Grow();
				lines.insert(lines.end(), newLines.begin(), newLines.end());
				timeSinceLastGrow = 0;
				iterations++;
			}
			Point range = Point(255, 400, 255);
			renderer->DrawPoints(points, range);
			renderer->DrawEdges(lines, range);
			renderer->DrawGUI(*gui, &GUI::DrawFrame);
			const auto sec = timer.Mark(); // seconds counter
			timeSinceLastGrow += sec;
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

std::unordered_map<Species_ID, int>& Engine::GetSpecies()
{
	return treesMap;
}