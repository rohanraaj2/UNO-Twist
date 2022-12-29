
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Sound.hpp"
#include "UNO.hpp"
using namespace std;

class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 600;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    
    UNO& uno {UNO::get_instance()};
    // UNO uno;

public:

	Sound * s = new Sound();

    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture( std::string path );
    void run();
	// UNO& uno {UNO::get_instance()};
    // void game_state(string status, int xMouse, int yMouse);
};

