#include "Non_Numbered.hpp"

Non_Numbered::Non_Numbered() {}

Non_Numbered::Non_Numbered(string CardId, string CardDesc):  Coloured{CardId, CardDesc}
{
    if (CardDesc == "Draw Two")
    {
        g.set_src_rect_x(g.get_src_rect().x + 1143);
        // g.set_src_rect_x(1143);
    }
    else if (CardDesc == "Reverse")
    {
        g.set_src_rect_x(g.get_src_rect().x + 1216);

        // g.set_src_rect_x(1216);
    }
    else if (CardDesc == "Skip")
    {
        g.set_src_rect_x(g.get_src_rect().x + 1289);
        // g.set_src_rect_x(1289);
    }
}

string Non_Numbered::GetCardId () 
{
    return CardId;
}

string Non_Numbered::GetCardDesc () 
{
    return CardDesc;
}