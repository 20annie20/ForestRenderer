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
	/**
	* \brief Clears render target.
	*/
	virtual void Clear() = 0;

	/**
	* \brief Draws points to the render target.
	* \param points - Array of points to draw.
	* \param range - View range.
	*/
	virtual void DrawPoints( const std::vector<struct ColoredPoint>& points, const struct Point& range ) = 0;

	/**
	* \brief Draws edges to the render target.
	* \param edges - Array of edges to draw.
	* \param range - View range.
	*/
	virtual void DrawEdges( const std::vector<std::pair<struct ColoredPoint, struct ColoredPoint>>& edges, const struct Point& range) = 0;

	/**
	* \brief Draws GUI to the render target.
	* \param gui - GUI to draw.
	* \param drawFunc - GUI drawing function to use.
	*/
	virtual void DrawGUI(class GUI& gui, void(GUI::*drawFunc)() ) = 0;

	/**
	* \brief Draws accumulated points and edges to the render target.
	*/
	virtual void RenderFromTexture() = 0;

	/**
	* \brief Presents the render target to screen.
	*/
	virtual void Present() = 0;

	/**
	* Releases renderer's resources.
	*/
	virtual void Cleanup() = 0;
};