#pragma once
#include <vector>
#include <utility>

class Renderer
{

public:
	virtual void DrawPoints( std::vector<struct ColoredPoint>, const struct Point& range ) = 0;
	virtual void DrawEdges( std::vector<std::pair<struct ColoredPoint, struct ColoredPoint>>, const struct Point& range) = 0;
};