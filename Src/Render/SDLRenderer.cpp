#include "SDLRenderer.h"

void SDLRenderer::TransformPoint(const Point& in, Point& out, const Point& range)
{
    Point e(0, 100, 255);
    int x = (window.GetWidth() / range.x) * in.x;
    int y = (range.y / window.GetHeight()) * in.y;
    out.x = (e.z / in.z) * x + e.x;
    out.y = ((e.z / in.z) * y + e.y);
}

void SDLRenderer::DrawPoints( std::span<Point> points, const Point& range )
{
    Point outPoint = Point();
    
    for( auto& point : points )
    {
        TransformPoint( point, outPoint, range );
        SetColor(point.color);
        if(point.color == ColorType::Green)
            SDL_RenderDrawLine(rend, outPoint.x, outPoint.y, outPoint.x, outPoint.y + 50);
        else
            SDL_RenderDrawPoint( rend, outPoint.x, outPoint.y );       
    }
    SDL_RenderPresent( rend );
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
    default:
        SDL_SetRenderDrawColor(rend, 255, 165, 0, 255);
    }
}

void SDLRenderer::DrawEdges(std::span<std::pair<Point, Point>> edges)
{
}
