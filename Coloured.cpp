#include "Coloured.hpp"

Coloured::Coloured() {}

Coloured::Coloured(string CardId, string CardDesc): Card {CardId, CardDesc}
{
    if (CardId == "Red")
    {
        g.set_src_rect_y(123);
        g.set_src_rect_x(1);
    }
    else if (CardId == "Green")
    {
        g.set_src_rect_y(239);
        g.set_src_rect_x(0);
    }
    else if (CardId == "Blue")
    {
        g.set_src_rect_y(355);
        g.set_src_rect_x(0);
    }
    else if (CardId == "Yellow")
    {
        g.set_src_rect_y(471);
        g.set_src_rect_x(0);
    }
}