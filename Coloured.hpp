#pragma once
#include "Card.hpp"
#include <string>


class Coloured : public Card
{
    public:
    Coloured();
    Coloured(string CardId, string CardDesc);
};

