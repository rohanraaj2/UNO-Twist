#include "Sound.hpp"

Sound::Sound()
{
    if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 ) 
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    if (Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) 
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    success = true;
    pSound = Mix_LoadWAV("flipcard.mp3");
    sMusic = Mix_LoadMUS ("starting music.mp3");
    mMusic = Mix_LoadMUS ("mid game.mp3");
    losemus = Mix_LoadMUS("lose.mp3");
    wSound = Mix_LoadWAV("win.wav");
    if( pSound == NULL) 
    {
        printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
}

void Sound::pick_card(bool play) 
{
    if (play)
    {
        Mix_PlayChannel(-1, pSound, 0);
    }
    else
    {
        Mix_FreeChunk(pSound);
    }
}

void Sound::starting_music(bool play) 
{
    if (play)
    {
        Mix_PlayMusic (sMusic, -1);
    }
    else
    {
        Mix_FreeMusic(sMusic);
    }
}
void Sound::mid_game(bool play)
{
    if (play)
    {
        Mix_PlayMusic (mMusic, -1);
    }
    else
    {
        Mix_FreeMusic(mMusic);
    }
}
void Sound::losemusic() 
{
    Mix_PlayMusic (losemus, -1);
}
void Sound::winsound()
{
    Mix_PlayChannel(-1, wSound, 0);
}