#pragma once
#include "drawing.hpp"

class Graphics
{
    SDL_Rect srcRect, moverRect;

    public:

    void draw(int x, int y);
    Graphics();
    SDL_Rect get_src_rect();
    SDL_Rect get_mover_rect();

    void set_src_rect(int x, int y, int w, int h);
    void set_mover_rect(int x, int y, int w, int h);

    void set_src_rect_size(int w, int h);
    void set_mover_rect_size(int w, int h);
    
    void set_src_rect_x(int x);
    void set_src_rect_y(int y);
    void set_src_rect_w(int w);
    void set_src_rect_h(int h);

    void set_mover_rect_x(int x);
    void set_mover_rect_y(int y);
    void set_mover_rect_w(int w);
    void set_mover_rect_h(int h);

};