#include "Player.hpp"
using namespace std;

Player::Player(std::string name, int deck_size) : m_name(name), m_deck_size(deck_size) {}

bool Player::pick_card(Card* picked_card)
{
        // if (m_player_deck.size() < m_player_deck.capacity())
        // {
    for(int i=0; i<m_deck_size; i++)
    {
        if( m_player_deck[i] == nullptr )
        {
            m_player_deck[i] = picked_card;
            return true;
        }
    }

    m_player_deck.push_back(picked_card);
    // std::cout<<"\n Error inserting the card because the player deck is already full\n.";
    return true;

        // }
    // for(int i=0; i<5; i++)
    // {
    //     if(m_player_deck[i]==0)                 // vector initialization with size has generated all the 7 elements with value 0.
    //     {                                       // no card will be assigned value 0, hence we can safely assume value 0 as      
    //         m_player_deck[i] = card_val;        // an empty spot in player's deck and can put there a card.
    //         return;
    //     }
    // }
}

bool Player::deck_is_empty()
{
    int c = 0; 
    while ( c < m_deck_size )
    {
        if ( m_player_deck[c]!=0 )
        {
            return false;
        }
        c+=1;
    }
    return true;
}

vector <Card*>& Player::get_deck()
{
    return m_player_deck;
}
