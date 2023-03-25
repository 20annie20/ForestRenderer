#include "Engine.h"
#include "SDLRenderer.h"
#include <filesystem>

Engine::Engine()
{
	renderer = new SDLRenderer();
}

Engine::~Engine()
{
	delete renderer;
}

void Engine::Run()
{
	Point range = Point(255, 400, 255);
	renderer->drawPoints(terrain.getPoints(), range);

	// renderer->Run(); // to show the animation
}

void Engine::Cleanup()
{
}