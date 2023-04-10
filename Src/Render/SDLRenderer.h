#pragma once
#include "Render\Renderer.h"
#include "Render\GUI.h"
#include "App\Window.h"
#include "Common.h"
#include <vector>

class SDLRenderer : public Renderer
{
	Window& window = Window::GetInstance();
	Uint32 renderFlags = SDL_RENDERER_ACCELERATED;
	SDL_Renderer* rend = SDL_CreateRenderer(window.GetSdlWindow(), -1, renderFlags);
	
	void TransformPoint(const Point& in, Point& out, const Point& range);
	void SetColor(const ColorType& color);

public:	
	SDLRenderer();
	void DrawPoints(const std::vector<ColoredPoint>&, const Point& range);
	void DrawEdges( const std::vector<std::pair<ColoredPoint, ColoredPoint>>&, const Point& range);
	void DrawGUI( GUI& gui );
	void Present();
};