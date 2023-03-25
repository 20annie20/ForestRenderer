#pragma once
#include <span>
#include <utility>

class Renderer
{

public:
	virtual void DrawPoints( std::span<struct Point>, const Point& range ) = 0;
	virtual void DrawEdges( std::span<std::pair<struct Point, struct Point>>, const Point& range) = 0;
};