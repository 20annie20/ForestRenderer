#pragma once
#include "Render\Renderer.h"
#include "App\Window.h"
#include "Common.h"

class SDLRenderer : public Renderer
{
	Window& window = Window::GetInstance();

	void drawPoints( std::span<Point> );
	void drawEdges( std::span<std::pair<Point, Point>> );
};