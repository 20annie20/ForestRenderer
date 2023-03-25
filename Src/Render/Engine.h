#pragma once

#include "Renderer.h"
#include "Algorithm\Terrain.h"

class Renderer;

class Engine
{
	Terrain terrain;
public:
	Engine();
	~Engine();
	void Run();
	void Cleanup();
private:
	Renderer* renderer;
};