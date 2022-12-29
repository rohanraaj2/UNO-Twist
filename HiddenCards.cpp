#include "HiddenCards.hpp"

HiddenCards::HiddenCards() {}

HiddenCards::HiddenCards(string size)
{
    if (size == "Small")
    {
        g.set_src_rect_w(49);
        g.set_src_rect_h(73);
        g.set_src_rect_x(78);
    }
    else if (size == "Big")
    {
        g.set_src_rect_w(70);
        g.set_src_rect_h(107);
        g.set_src_rect_x(5);
    }
    g.set_src_rect_y(21);
    g.set_mover_rect(450, 100, g.get_src_rect().w, g.get_src_rect().h);
}
