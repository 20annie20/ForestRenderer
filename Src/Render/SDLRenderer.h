#pragma once
#include "Render\Renderer.h"
#include "Render\GUI.h"
#include "App\Window.h"
#include "Common.h"
#include <vector>

/// Renderer interface realizing class using SDL2 library
/** Initalizes required SDL state and utilites, draws objects using perspective transformation and contains all typical
* render class functions such as: clear, present. Uses rendering from texture to optimise performance.
*/
class SDLRenderer : public Renderer
{
	Window& window = Window::GetInstance();
	Uint32 renderFlags = SDL_RENDERER_ACCELERATED;
	SDL_Renderer* rend = SDL_CreateRenderer(window.GetSdlWindow(), -1, renderFlags);
	SDL_Texture* texTarget = SDL_CreateTexture(rend, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, window.GetWidth(), window.GetHeight());
	
	void TransformPoint(const Point& in, Point& out, const Point& range);
	void SetColor(const ColorType& color);

public:
	/**
	* \brief Constructs an SDL2-based renderer.
	*/
	SDLRenderer();

	/**
	* \brief Draws points to the render target.
	* \param points - Array of points to draw.
	* \param range - View range.
	*/
	void DrawPoints(const std::vector<ColoredPoint>&, const Point& range ) final;

	/**
	* \brief Draws edges to the render target.
	* \param edges - Array of edges to draw.
	* \param range - View range.
	*/
	void DrawEdges( const std::vector<std::pair<ColoredPoint, ColoredPoint>>&, const Point& range ) final;

	/**
	* \brief Draws GUI to the render target.
	* \param gui - GUI to draw.
	* \param drawFunc - GUI drawing function to use.
	*/
	void DrawGUI( GUI& gui, void(GUI::* drawFunc)() ) final;

	/**
	* \brief Draws accumulated points and edges to the render target.
	*/
	void RenderFromTexture() final;

	/**
	* \brief Presents the render target to screen.
	*/
	void Present() final;

	/**
	* Releases renderer's resources.
	*/
	void Cleanup() final;

	/**
	* \brief Clears render target.
	*/
	void Clear() final;
};