#include "Human.hpp"
using namespace std;

Human::Human(std::string name , int deck_size): Player(name = "Human new", deck_size)
{
}

Card* Human::drop_card(Card* card_obj, Card* prev_card, std::string wild_color){
    
    // Card* to_return = 
    std::cout<<"\n in human drop card func \n ";
    if (card_obj->verify_dropped_card(prev_card,wild_color) == true)  // verification to drop the right card
    {
        for(int i = 0; i< m_player_deck.size(); i++)
        {
            if ((card_obj) == (m_player_deck[i]))
            {
                delete m_player_deck[i]; // nullptr is saved as 0 in vector.
                m_player_deck[i] = nullptr; // nullptr is saved as 0 in vector.
                m_player_deck.erase(m_player_deck.begin()+i); // removes object from vector list
            }
        }
        return card_obj; // we need to return this card so that we know that the next card dropped should follow the rules of UNO.
    }
    else
    {
        return nullptr;
    }
}
