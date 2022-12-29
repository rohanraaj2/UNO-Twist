#include "Graphics.hpp"

using namespace std;
void Graphics::draw(int x, int y)
{
    moverRect = {x, y, srcRect.w, srcRect.h};
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect); // drawing the object
}

Graphics::Graphics() {}

SDL_Rect Graphics::get_src_rect()
{
    return srcRect;
}

SDL_Rect Graphics::get_mover_rect()
{
    return moverRect;
}

void Graphics::set_src_rect(int x, int y, int w, int h)
{
    Graphics::set_src_rect_x(x);
    Graphics::set_src_rect_y(y);
    Graphics::set_src_rect_size(w, h);
    
}
void Graphics::set_mover_rect(int x, int y, int w, int h)
{
    Graphics::set_mover_rect_x(x);
    Graphics::set_mover_rect_y(y);
    Graphics::set_mover_rect_size(w, h);
}
void Graphics::set_src_rect_size(int w, int h)
{
    Graphics::set_src_rect_w(w);
    Graphics::set_src_rect_h(h);   
}
void Graphics::set_mover_rect_size(int w, int h)
{
    Graphics::set_mover_rect_w(w);
    Graphics::set_mover_rect_h(h);   
}

void Graphics::set_src_rect_x(int x)
{
    srcRect.x = x;
}
void Graphics::set_src_rect_y(int y)
{
    srcRect.y = y;
}
void Graphics::set_src_rect_w(int w)
{
    srcRect.w = w;
}
void Graphics::set_src_rect_h(int h)
{
    srcRect.h = h;
}
void Graphics::set_mover_rect_x(int x)
{
    moverRect.x = x;
}
void Graphics::set_mover_rect_y(int y)
{
    moverRect.y = y;
}
void Graphics::set_mover_rect_w(int w)
{
    moverRect.w = w;
}
void Graphics::set_mover_rect_h(int h)
{
    moverRect.h = h;
}