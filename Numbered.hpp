#pragma once
#include "Coloured.hpp"
#include <string>

class Numbered : public Coloured
{

    public:
    Numbered();
    Numbered(string id, string desc);
    string GetCardId () override;
    string GetCardDesc () override;
    
};