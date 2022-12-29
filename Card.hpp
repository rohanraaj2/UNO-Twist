#pragma once
#include "Graphics.hpp"
#include <string>

// using namespace std;

class Card
{ 
    protected:
    string CardId, CardDesc;

    public:
    Graphics g;
    Card();
    // virtual void draw() = 0 ; // since Card is abstract class function has to be a pure virtual function re-define it in children where needed
    Card(string CardId, string CardDesc);
    virtual string GetCardId () = 0; // is virtual function in an abstract class which will be redefined in the children/grand children
    virtual string GetCardDesc () = 0; // GetCardid() will tell us if the card is colored or non-colored, while GetCardDesc will get us the description like "skip" or 1
    bool verify_dropped_card (Card* prev_card, std::string wild_color);
    
};