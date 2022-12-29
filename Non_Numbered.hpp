#pragma once
#include "Coloured.hpp"
#include <string>

class Non_Numbered : public Coloured
{
    public:

    Non_Numbered();
    Non_Numbered(string CardId, string CardDesc);
    string GetCardId () override;
    string GetCardDesc () override;
};