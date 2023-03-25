#pragma once
#include <span>
#include <utility>

class Renderer
{

public:
	virtual void drawPoints( std::span<struct Point>, const Point& range ) = 0;
	virtual void drawEdges( std::span<std::pair<struct Point, struct Point>>) = 0;
};