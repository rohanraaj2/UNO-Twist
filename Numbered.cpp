#include "Numbered.hpp"

Numbered::Numbered() {}

Numbered::Numbered(string CardId, string CardDesc): Coloured{CardId, CardDesc}
{
    if (CardDesc == "0")
    {
        g.set_src_rect_x(g.get_src_rect().x + 1070);
        // g.set_src_rect_x(1070);
    }
    else if (CardDesc == "1")
    {
        g.set_src_rect_x(g.get_src_rect().x + 413);
        
        // g.set_src_rect_x(413);
    }
    else if (CardDesc == "2")
    {
        g.set_src_rect_x(g.get_src_rect().x + 486);

        // g.set_src_rect_x(486);
    }
    else if (CardDesc == "3")
    {
        g.set_src_rect_x(g.get_src_rect().x + 559);

        // g.set_src_rect_x(559);
    }
    else if (CardDesc == "4")
    {
        g.set_src_rect_x(g.get_src_rect().x + 632);

        // g.set_src_rect_x(632);
    }
    else if (CardDesc == "5")
    {
        g.set_src_rect_x(g.get_src_rect().x + 705);

        // g.set_src_rect_x(705);
    }
    else if (CardDesc == "6")
    {
        g.set_src_rect_x(g.get_src_rect().x + 778);

        // g.set_src_rect_x(778);
    }
    else if (CardDesc == "7")
    {
        g.set_src_rect_x(g.get_src_rect().x + 851);

        // g.set_src_rect_x(851);
    }
    else if (CardDesc == "8")
    {
        g.set_src_rect_x(g.get_src_rect().x + 924);

        // g.set_src_rect_x(924);
    }
    else if (CardDesc == "9")
    {
        g.set_src_rect_x(g.get_src_rect().x + 997);
        // g.set_src_rect_x(997);
    }
}

string Numbered::GetCardId ()
{
    return CardId;
    
}
string Numbered::GetCardDesc ()
{
    return CardDesc;
}
