// Checks if _PLAYERS_ IF DECLARED
#ifndef _PLAYERS_
  
// Defines _PLAYERS_ if above
// conditions fails
#define _PLAYERS_

#include "drawing.hpp"
#include<SDL.h>
#include <iostream>
#include <vector>
#include "Card.hpp"
using namespace std;



class Player{
    int m_deck_size;    
    std::string m_name;

    protected:
    Player(std::string name, int deck_size = 7);
    std::vector<Card*> m_player_deck {std::vector<Card*> (m_deck_size)};


    public:
    bool pick_card(Card* picked_card);
    virtual Card* drop_card(Card* card_obj, Card* prev_card, std::string wild_color) = 0;
    // std::vector<Card*> get_deck();
    bool deck_is_empty();
    vector <Card*>& get_deck();
};

#endif