#pragma once
#include <vector>
#include <utility>

/// Abstract interface of renderer component
/** Renderer is responsible for showing data processed by the application algorithms in a visual form on the screen. 
It contains typical drawing functions like: clear the previous frame, show frame when it's ready, draw edges, draw points, draw GUI.
At the end of program lifetime renderer cleans up the necessary contexts and clean remained objects.
*/
class Renderer
{

public:
	virtual void Clear() = 0;
	virtual void DrawPoints( const std::vector<struct ColoredPoint>&, const struct Point& range ) = 0;
	virtual void DrawEdges( const std::vector<std::pair<struct ColoredPoint, struct ColoredPoint>>&, const struct Point& range) = 0;
	virtual void DrawGUI(class GUI& gui, void(GUI::*drawFunc)() ) = 0;
	virtual void RenderFromTexture() = 0;
	virtual void Present() = 0;
	virtual void Cleanup() = 0;
};