#include "Non_Coloured.hpp"

Non_Coloured::Non_Coloured() {}

Non_Coloured::Non_Coloured (string CardDesc) : Card {"NC", CardDesc}
{
    g.set_src_rect_y(587);
    if (CardDesc == "Wild")
    {
        g.set_src_rect_x(413);
    }
    else if (CardDesc == "Draw Four")
    {
        g.set_src_rect_x(778);
    }
}

string Non_Coloured:: GetCardId () 
{
    return CardId;
}

string Non_Coloured:: GetCardDesc () 
{
    return CardDesc;
}
