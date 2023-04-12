#include "Window.h"

Window::Window() {}

/** 
* Singleton function to access single instance of a window object
* 
* \return instance of a window object
*/
Window& Window::GetInstance()
{
	static Window window_;
	return window_;
}

/**
* Initializes SDL window and sets its basic parameters
*
* \param[in] windowTitle - title displayed at the top of the window
* \param[in] width - width of the window (in pixels)
* \param[in] height - height of the window (in pixels)
*/
void Window::InitWindow(const char* windowTitle, const int width, const int height)
{
	this->width = width;
	this->height = height;
	SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_SHOWN);
	sdlWindow = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, window_flags);
	if (sdlWindow == NULL)
	{
		throw std::runtime_error( SDL_GetError() );
	}
	showDemoWindow = true;
}

int Window::GetWidth() const { return width; }

int Window::GetHeight() const {	return height; }

SDL_Window* Window::GetSdlWindow() const { return sdlWindow; }

void Window::DestroyWindow()
{
	SDL_DestroyWindow(sdlWindow);
}
