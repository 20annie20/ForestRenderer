#pragma once
#include <vector>
#include <utility>

class Renderer
{

public:
	virtual void DrawPoints( const std::vector<struct ColoredPoint>&, const struct Point& range ) = 0;
	virtual void DrawEdges( const std::vector<std::pair<struct ColoredPoint, struct ColoredPoint>>&, const struct Point& range) = 0;
	virtual void DrawGUI(class GUI& gui) = 0;
	virtual void Present() = 0;
};