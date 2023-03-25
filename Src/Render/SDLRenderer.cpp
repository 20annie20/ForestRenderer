#include "SDLRenderer.h"

SDLRenderer::SDLRenderer()
{
    setProjectionMatrix();
}

void SDLRenderer::setProjectionMatrix()
{
    float angleOfView = 90;
    float near = 0.1;
    float far = 100;

    float scale = 1 / tan(angleOfView * 0.5 * M_PI / 180);
    matrix.ProjectionMatrix[0][0] = scale;  //scale the x coordinates of the projected point 
    matrix.ProjectionMatrix[1][1] = scale;  //scale the y coordinates of the projected point 
    matrix.ProjectionMatrix[2][2] = -far / (far - near);  //used to remap z to [0,1] 
    matrix.ProjectionMatrix[2][3] = -far * near / (far - near);  //used to remap z [0,1] 
    matrix.ProjectionMatrix[3][2] = -1;  //set w = -z 
    matrix.ProjectionMatrix[3][3] = 0;
}

void SDLRenderer::transformPoint(const Point& in, Point& out, const Point& range)
{
    Point e(0, 100, 255);
    int x = (window.getWidth() / range.x) * in.x;
    int y = (range.y / window.getHeight()) * in.y;
    out.x = (e.z / in.z) * x + e.x;
    out.y = ((e.z / in.z) * y + e.y);
}

void SDLRenderer::drawPoints( std::span<Point> points, const Point& range )
{
    Point outPoint = Point();
    
    for( auto& point : points )
    {
        transformPoint( point, outPoint, range );
        SDL_RenderDrawPoint( rend, outPoint.x, outPoint.y );
        setColor(point.color);
    }
    SDL_RenderPresent( rend );
}

void SDLRenderer::setColor(const ColorType& color)
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
    default:
        SDL_SetRenderDrawColor(rend, 255, 165, 0, 255);
    }
}

void SDLRenderer::drawEdges(std::span<std::pair<Point, Point>> edges)
{
}
