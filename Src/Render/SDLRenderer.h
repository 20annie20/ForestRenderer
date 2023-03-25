#pragma once
#include "Render\Renderer.h"
#include "App\Window.h"
#include "Common.h"

class SDLRenderer : public Renderer
{
	Window& window = Window::GetInstance();
	Uint32 render_flags = SDL_RENDERER_ACCELERATED;
	SDL_Renderer* rend = SDL_CreateRenderer(window.getSdlWindow(), -1, render_flags);
	
	struct ProjectionMatrix
	{
		float ProjectionMatrix[4][4];
	};
	
	ProjectionMatrix matrix;
	void setProjectionMatrix();
	void transformPoint(const Point& in, Point& out, const Point& range);
	void setColor(const ColorType& color);

public:	
	SDLRenderer();
	void drawPoints( std::span<Point>, const Point& range);
	void drawEdges( std::span<std::pair<Point, Point>> );
};