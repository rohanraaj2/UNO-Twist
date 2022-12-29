#pragma once
#include "drawing.hpp"
#include<SDL.h>
#include <iostream>
#include <vector>
#include "Player.hpp"
using namespace std;


class Human : public Player
{
    public:
    Human(std::string name , int deck_size);

    Card* drop_card(Card* card_obj, Card* prev_card, std::string wild_color) override;
};