#include "Card.hpp"

Card::Card() 
{
    g.set_src_rect_w(70);
    g.set_src_rect_h(107);
    g.set_mover_rect(450, 450, 70, 107);
}

Card::Card(string Card_Id, string Card_Desc) : CardId{Card_Id}, CardDesc{Card_Desc}
{
    g.set_src_rect_w(70);
    g.set_src_rect_h(107);
    g.set_mover_rect(450, 450, 70, 107);
}

bool Card::verify_dropped_card (Card* prev_card, std::string wild_color)
{   
    // std::string req_col = "Red";
    if (prev_card->CardId == "NC")
    {
        if (this->CardId == wild_color)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(this->CardId == "NC")    //non colored cards can be dropeed anytime without condition
        {
            return true;
        }
        else      // cards are colored than
        {
            if ( (this->CardDesc) == (prev_card->CardDesc) || (this->CardId) == (prev_card->CardId) ) // either card should be same color(CardDesc)
            {                                                                                                 // or of same number(CardId)
                return true;
            }
            else 
            {
                return false;
            }
        }
    }
    
}

