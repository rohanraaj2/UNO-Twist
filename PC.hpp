#pragma once
#include "drawing.hpp"
#include<SDL.h>
#include <iostream>
#include <vector>
#include "Player.hpp"
#include <ctime>
// #include "Card.hpp"
using namespace std;

class PC : public Player
{
    public:
    PC(std::string name , int deck_size);

    Card* drop_card(Card* card_obj, Card* prev_card, std::string wild_color)  override;
    // bool pick_card( Card* prev_card);
    std::string choose_wild_color();

};
