#include "SDLRenderer.h"

void SDLRenderer::TransformPoint(const Point& in, Point& out, const Point& range)
{
    Point e(100, 150, 450);
    int x = (window.GetWidth() / 513) * in.x;
    int y = (window.GetHeight() - 2 * e.y ) / 513  * in.y - e.y;
    out.x = (e.z / in.z) * x;
    out.y = ((e.z / in.z) * (-y) + e.y);
}

void SDLRenderer::DrawPoints( std::vector<ColoredPoint> points, const Point& range )
{
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

void SDLRenderer::DrawEdges(std::vector<std::pair<ColoredPoint, ColoredPoint>> edges, const Point& range)
{
    ColoredPoint outPoint1 = ColoredPoint();
    ColoredPoint outPoint2 = ColoredPoint();

    for (auto& edge : edges)
    {
        TransformPoint(edge.first, outPoint1, range);
        TransformPoint(edge.second, outPoint2, range);
        SetColor(edge.first.color);
        SDL_RenderDrawLine(rend, outPoint1.x, outPoint1.y, outPoint2.x, outPoint2.y);
    }
    SDL_RenderPresent(rend);
}
