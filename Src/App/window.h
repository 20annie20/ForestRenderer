#pragma once
#include <SDL.h>
#include <iostream>

/// Window class
/** Singleton window class, maintaining instance of an SDL window */
class Window {

    SDL_Window* sdlWindow = NULL;
    int width = 0;
    int height = 0;
    bool showDemoWindow = true;
    Window();

public:
    Window(Window& other) = delete;
    void operator=(const Window&) = delete;

    /**
    * \returns An instance of the Window singleton.
    */
    static Window& GetInstance();

    /**
    * \brief Initializes the window instance.
    * \param windowTitle - Title of the window to display on the titlebar.
    * \param width - Width of the window's client area.
    * \param height - Height of the window's client area.
    */
    void InitWindow(const char* windowTitle, const int width, const int height);

    /**
    * \returns Width of the window's client area.
    */
    int GetWidth() const;

    /**
    * \returns Height of the window's client area.
    */
    int GetHeight() const;

    /**
    * \returns Native SDL_Window handle.
    */
    SDL_Window* GetSdlWindow() const;

    /**
    * \brief Destroys the window.
    */
    void DestroyWindow();
};