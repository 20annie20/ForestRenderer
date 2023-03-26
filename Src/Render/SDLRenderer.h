#pragma once
#include "Render\Renderer.h"
#include "App\Window.h"
#include "Common.h"
#include <vector>

class SDLRenderer : public Renderer
{
	Window& window = Window::GetInstance();
	Uint32 render_flags = SDL_RENDERER_ACCELERATED;
	SDL_Renderer* rend = SDL_CreateRenderer(window.GetSdlWindow(), -1, render_flags);
	
	void TransformPoint(const Point& in, Point& out, const Point& range);
	void SetColor(const ColorType& color);

public:	
	void DrawPoints( std::vector<ColoredPoint>, const Point& range);
	void DrawEdges( std::vector<std::pair<ColoredPoint, ColoredPoint>>, const Point& range);
};