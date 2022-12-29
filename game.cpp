#include "game.hpp"
#include "UNO.hpp"
#include "drawing.hpp"
using namespace std;

SDL_Renderer* Drawing::gRenderer = NULL;
SDL_Texture* Drawing::assets = NULL;

bool Game::init()
{
	//Initialization flag
	bool success = true;


	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "UNO Revived", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			Drawing::gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( Drawing::gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	
	Drawing::assets = loadTexture("assets.png");
    gTexture = loadTexture("starting screen.png");
	if(Drawing::assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	s->starting_music("game loaded");
	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(Drawing::assets);
	Drawing::assets=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( Drawing::gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	Drawing::gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( Drawing::gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}
void Game::run( )
{
	string status = "menu";
	string background = "starting screen.png";
	// bool wild_screen = false;
	bool quit = false;
	SDL_Event e;

	// UNO& uno {UNO::get_instance()};
	uno.game_initialization();
	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}

			if(e.type == SDL_MOUSEBUTTONDOWN){
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
                cout << xMouse << " & " << yMouse << endl;

				if (status == "menu")
				{
					if (yMouse > 534 && yMouse < 599)
					{
						if (xMouse > 392 && xMouse < 500)
						{
							background = "background choosing.png";
							gTexture = loadTexture(background);
							status = "choosing background";
						}
						else if (xMouse > 562 && xMouse < 670)
						{
							background = "UNO Rules.png";
							gTexture = loadTexture(background);
							status = "reading instructions";
						}
					}
					else if (xMouse > 131 && xMouse < 235 && yMouse > 15 && yMouse < 77)
					{
						quit = true;
					}
				}
				if (status == "reading instructions")
				{
					if (xMouse > 23 && xMouse < 296 && yMouse > 561 && yMouse < 594)
					{
						if (xMouse > 35 && xMouse < 171 && yMouse > 551 && yMouse < 596)
						{
							background = "background choosing.png";
							gTexture = loadTexture(background);
							status = "choosing background";
						}
					}
				}
				if (status == "choosing background")
				{
					if (xMouse > 35 && xMouse < 459 && yMouse > 151 && yMouse < 392)
					{
						s->starting_music(false);
						background = "grass background.png";
						gTexture = loadTexture(background);
						status = "game started";
						s->mid_game(true);
					}
					else if (xMouse > 555 && xMouse < 971 && yMouse > 154 && yMouse < 384)
					{
						s->starting_music(false);
						background = "wooden background.png";
						gTexture = loadTexture(background);
						status = "game started";
						s->mid_game(true);
					}
					else if (xMouse > 119 && xMouse < 229 && yMouse > 13 && yMouse < 79)
					{
						quit = true;
					}
				}
				if (status == "game started")
				{
					// string card_checker;
					// bool wild_screen = false;
					uno.Click(xMouse, yMouse);
					if (xMouse > 25 && xMouse < 189 && yMouse > 20 && yMouse < 73)
					{
						quit = true;
					}
					// card_checker = uno.wild_card_check (Card * card, string player)
					if (uno.get_wild_by_human_signal() || uno.get_draw_four_by_human_signal())
					{
						if (uno.get_wild_by_human_signal())
						{
							gTexture = loadTexture("Wild.png");
						}
						else if (uno.get_draw_four_by_human_signal())
						{
							gTexture = loadTexture("Draw_4.png");
						}
					}
					else
					{
						gTexture = loadTexture(background);
					}
					if (uno.get_winner() == "Human" || uno.get_winner() == "PC")
					{
						s->mid_game(false);
						status = "game concluded";
					}
				}
				if (status == "game concluded")
				{
					if (uno.get_winner() == "Human")
					{
						gTexture = loadTexture("won.png");
						s->winsound();
					}
					else if (uno.get_winner() == "PC")
					{
						gTexture = loadTexture("lost.png");
						s->losemusic();
					}
				}
			}
		}

		SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************
		if (status == "game started" && !uno.get_wild_by_human_signal() && !uno.get_draw_four_by_human_signal())
		{
			uno.drawObjects();
		}
		//****************************************************************
    	SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer

	    SDL_Delay(100);	//causes sdl engine to delay for specified miliseconds
	}
			
}