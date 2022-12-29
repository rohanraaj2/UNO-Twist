#include "PC.hpp"
using namespace std;

PC::PC(std::string name , int deck_size): Player(name = "PC new", deck_size)
{

}

Card* PC::drop_card(Card* card_obj, Card* prev_card, std::string wild_color){
    
    std:cout<<"\n in PC drop card func \n ";

    card_obj = nullptr;
    int c = 0;
    while( c < m_player_deck.size() )  // verification to drop the right card
    {
        if ( m_player_deck[c] -> verify_dropped_card (prev_card,wild_color) == true)
        {
            Card* card_to_return = m_player_deck[c]; // we need to return this card so that we know that the next card dropped should follow the rules of UNO.
            delete m_player_deck[c];
            m_player_deck[c] = nullptr; // nullptr is saved as 0 in vector.
            m_player_deck.erase(m_player_deck.begin()+c); // removes object from vector list

            return card_to_return;
        }
        c+=1;

    }
    
    return nullptr;


}

std::string PC::choose_wild_color()
{
    int c;
    srand((unsigned) time(NULL));
    c = 1+((rand() % 4));

    if (c==1)
    {
        return "Red";
    } 
    else if(c==2)
    {
        return "Blue";
    }
    else if (c==3)
    {
        return "Green";
    }
    else if (c==4)
    {
        return "Yellow";
    }
}

// bool PC::pick_card(Card* prev_card){
//     // implementation of computer card picking.
//     Card* picked_card = nullptr; // some selected card from the main bank.
//     return Player::pick_card(picked_card, prev_card);
// }
