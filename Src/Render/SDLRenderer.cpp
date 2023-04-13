#include "SDLRenderer.h"

SDLRenderer::SDLRenderer()
{
    ImGui_ImplSDL2_InitForSDLRenderer(window.GetSdlWindow(), rend);
    ImGui_ImplSDLRenderer_Init(rend);
}

void SDLRenderer::TransformPoint(const Point& in, Point& out, const Point& range)
{
    int x = (window.GetWidth() / 513) * in.x;
    int y = (window.GetHeight() - 2 * range.y ) / 513  * in.y - range.y;
    out.x = (range.z / in.z) * x;
    out.y = ((range.z / in.z) * (-y) + range.y);
}

void SDLRenderer::DrawPoints( const std::vector<ColoredPoint>& points, const Point& range )
{
    SDL_SetRenderTarget(rend, texTarget);
    SDL_RenderClear(rend);
    SDL_SetRenderTarget(rend, texTarget);

    ColoredPoint outPoint = ColoredPoint();
    
    for( auto& point : points )
    {
        TransformPoint( point, outPoint, range );
        SetColor(point.color);

        if (point.color == ColorType::Green)
            SDL_RenderDrawLine(rend, outPoint.x, outPoint.y, outPoint.x, outPoint.y - 50);
        else
            SDL_RenderDrawPoint(rend, outPoint.x, outPoint.y);

        SDL_RenderDrawPoint(rend, outPoint.x, outPoint.y);
    }
    SDL_SetRenderTarget(rend, NULL);
}

void SDLRenderer::RenderFromTexture()
{
    SDL_RenderCopy(rend, texTarget, NULL, NULL);
}

void SDLRenderer::SetColor(const ColorType& color)
{
    switch(color)
    {
    case Brown:
        SDL_SetRenderDrawColor(rend, 144, 63, 63, 255);
        break;
    case Orange:
        SDL_SetRenderDrawColor(rend, 255, 165, 0, 255);
        break;
    case Yellow:
        SDL_SetRenderDrawColor(rend, 255, 255, 0, 255);
        break;
    case Grey:
        SDL_SetRenderDrawColor(rend, 128, 128, 128, 255);
        break;
    case Green:
        SDL_SetRenderDrawColor(rend, 0, 255, 0, 255);
        break;
    case DarkGreen:
        SDL_SetRenderDrawColor(rend, 38, 107, 13, 255);
        break;
    case Purple:
        SDL_SetRenderDrawColor(rend, 169, 18, 240, 255);
        break;
    default:
        SDL_SetRenderDrawColor(rend, 255, 165, 0, 255);
    }
}

void SDLRenderer::DrawEdges(const std::vector<std::pair<ColoredPoint, ColoredPoint>>& edges, const Point& range)
{
    ColoredPoint outPoint1 = ColoredPoint();
    ColoredPoint outPoint2 = ColoredPoint();

    SDL_SetRenderTarget(rend, texTarget);
    for (auto& edge : edges)
    {
        TransformPoint(edge.first, outPoint1, range);
        TransformPoint(edge.second, outPoint2, range);
        SetColor(edge.first.color);
        SDL_RenderDrawLine(rend, outPoint1.x, outPoint1.y, outPoint2.x, outPoint2.y);
    }
    SDL_SetRenderTarget(rend, NULL);
}

void SDLRenderer::DrawGUI(GUI& gui, void(GUI::* drawFunc)())
{
    ImGui_ImplSDLRenderer_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    (gui.*drawFunc)();
    ImGui_ImplSDLRenderer_RenderDrawData(
        ImGui::GetDrawData()
    );
}

void SDLRenderer::Present()
{
    SDL_RenderPresent(rend);
}

void SDLRenderer::Cleanup()
{
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}

void SDLRenderer::Clear()
{
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    SDL_SetRenderTarget(rend, NULL);
    SDL_RenderClear(rend);
}