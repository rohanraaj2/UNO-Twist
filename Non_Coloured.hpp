#pragma once
#include "Card.hpp"
#include <string>

class Non_Coloured : public Card
{
    public:
    Non_Coloured();
    Non_Coloured(string CardDesc);
    string GetCardId () override;
    string GetCardDesc () override;

};

