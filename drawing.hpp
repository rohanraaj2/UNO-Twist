#pragma once
#include<SDL.h>

using namespace std;
class Drawing{
    public:
        //The window renderer
    static SDL_Renderer* gRenderer;
    //global reference to png image sheets
    static SDL_Texture* assets;
};