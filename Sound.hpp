#pragma once
#include<SDL.h>
#include<SDL_mixer.h>
#include<SDL_image.h>
#include <string>
#include <iostream>


class Sound
{
    Mix_Chunk* pSound = NULL;
    Mix_Music* sMusic = NULL;
    Mix_Music* mMusic = NULL;
    // Mix_Chunk* lmusic = NULL;
    Mix_Music* losemus = NULL;
    Mix_Chunk* wSound = NULL;
    bool success;

    public:
    Sound();
    void pick_card(bool play);
    void starting_music(bool play);
    void mid_game(bool play);
    void losemusic();
    void winsound();
    // void music(string type_of_music);

};


