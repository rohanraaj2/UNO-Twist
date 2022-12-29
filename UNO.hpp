#pragma once
#include<SDL.h>
#include<vector>
#include<list>
#include "Numbered.hpp"
#include "Non_Numbered.hpp"
#include "Human.hpp"
#include "PC.hpp"
#include "Non_Coloured.hpp"
#include "HiddenCards.hpp"
#include <ctime>
#include "Player.hpp"
#include "Sound.hpp"

class UNO
{
    UNO ();
    UNO(const UNO& obj);
    HiddenCards a1 = {"Small"};
    HiddenCards right_most_card_of_bank = {"Big"};
    HiddenCards a9 = {"Big"};
    HiddenCards a10 = {"Big"};
    HiddenCards a11 = {"Big"};
    HiddenCards a12 = {"Big"};
    HiddenCards a13 = {"Big"};
    HiddenCards a14 = {"Big"};
    HiddenCards left_most_card_of_bank = {"Big"};

    Card*c0= new Numbered {"Red","0"};
    Card*c1= new Numbered {"Red", "1"};
    Card*c2= new Numbered {"Red","2"};
    Card*c3= new Numbered {"Red", "3"};
    Card*c4= new Numbered {"Red", "4"};
    Card*c5= new Numbered {"Red", "5"};
    Card*c6= new Numbered {"Red", "6"};
    Card*c7= new Numbered {"Red", "7"};
    Card*c8= new Numbered {"Red", "8"};
    Card*c9= new Numbered {"Red", "9"};
    Card*c10 = new Non_Numbered {"Red", "Skip"};
    Card*c11 = new Non_Numbered {"Red", "Skip"};
    Card*c12 = new Non_Numbered {"Red", "Reverse"};
    Card*c13 = new Non_Numbered {"Red", "Reverse"};
    Card*c14 = new Non_Numbered {"Red", "Draw Two"};
    Card*c15 = new Non_Numbered {"Red", "Draw Two"};
    Card*c16= new Numbered {"Green","0"};
    Card*c17= new Numbered {"Green", "1"};
    Card*c18= new Numbered {"Green","2"};
    Card*c19= new Numbered {"Green", "3"};
    Card*c20= new Numbered {"Green", "4"};
    Card*c21= new Numbered {"Green", "5"};
    Card*c22= new Numbered {"Green", "6"};
    Card*c23= new Numbered {"Green", "7"};
    Card*c24= new Numbered {"Green", "8"};
    Card*c25= new Numbered {"Green", "9"};
    Card*c26= new Numbered {"Green", "6"};
    Card*c27= new Numbered {"Green", "7"};
    Card*c28= new Numbered {"Green", "8"};
    Card*c29= new Numbered {"Green", "9"};
    Card*c30 = new Non_Numbered {"Green", "Skip"};
    Card*c31 = new Non_Numbered {"Green", "Skip"};
    Card*c32 = new Non_Numbered {"Green", "Reverse"};
    Card*c33 = new Non_Numbered {"Green", "Reverse"};
    Card*c34 = new Non_Numbered {"Green", "Draw Two"};
    Card*c35 = new Non_Numbered {"Green", "Draw Two"};

    Card*c36= new Numbered {"Yellow","0"};
    Card*c37= new Numbered {"Yellow", "1"};
    Card*c38= new Numbered {"Yellow","2"};
    Card*c39= new Numbered {"Yellow", "3"};
    Card*c40= new Numbered {"Yellow", "4"};
    Card*c41= new Numbered {"Yellow", "5"};
    Card*c42= new Numbered {"Yellow", "6"};
    Card*c43= new Numbered {"Yellow", "7"};
    Card*c44= new Numbered {"Yellow", "8"};
    Card*c45= new Numbered {"Yellow", "9"};
    Card*c46= new Numbered {"Yellow", "6"};
    Card*c47= new Numbered {"Yellow", "7"};
    Card*c48= new Numbered {"Yellow", "8"};
    Card*c49= new Numbered {"Yellow", "9"};
    Card*c50 = new Non_Numbered {"Yellow", "Skip"};
    Card*c51 = new Non_Numbered {"Yellow", "Skip"};
    Card*c52 = new Non_Numbered {"Yellow", "Reverse"};
    Card*c53 = new Non_Numbered {"Yellow", "Reverse"};
    Card*c54 = new Non_Numbered {"Yellow", "Draw Two"};
    Card*c55 = new Non_Numbered {"Yellow", "Draw Two"};

    Card*c56= new Numbered {"Blue","0"};
    Card*c57= new Numbered {"Blue", "1"};
    Card*c58= new Numbered {"Blue","2"};
    Card*c59= new Numbered {"Blue", "3"};
    Card*c60= new Numbered {"Blue", "4"};
    Card*c61= new Numbered {"Blue", "5"};
    Card*c62= new Numbered {"Blue", "6"};
    Card*c63= new Numbered {"Blue", "7"};
    Card*c64= new Numbered {"Blue", "8"};
    Card*c65= new Numbered {"Blue", "9"};
    Card*c66= new Numbered {"Blue", "6"};
    Card*c67= new Numbered {"Blue", "7"};
    Card*c68= new Numbered {"Blue", "8"};
    Card*c69= new Numbered {"Blue", "9"};
    Card*c70 = new Non_Numbered {"Blue", "Skip"};
    Card*c71 = new Non_Numbered {"Blue", "Skip"};
    Card*c72 = new Non_Numbered {"Blue", "Reverse"};
    Card*c73 = new Non_Numbered {"Blue", "Reverse"};
    Card*c74 = new Non_Numbered {"Blue", "Draw Two"};
    Card*c75 = new Non_Numbered {"Blue", "Draw Two"};

    Card*c76 = new Non_Coloured {"Draw Four"};
    Card*c77 = new Non_Coloured {"Draw Four"};
    Card*c78 = new Non_Coloured {"Draw Four"};
    Card*c79 = new Non_Coloured {"Draw Four"};
    
    Card*c80 = new Non_Coloured {"Wild"};
    Card*c81 = new Non_Coloured {"Wild"};
    Card*c82 = new Non_Coloured {"Wild"};
    Card*c83 = new Non_Coloured {"Wild"};

    std::vector<Card*> m_bank {c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c20, c21, c22, c23, c24, c25, c26, c27, c28, c29, c30, c31, c32, c33, c34, c35, c36, c37, c38, c39, c40, c41, c42, c43, c44, c45, c46, c47, c48, c49, c50, c51, c52, c53, c54, c55, c56, c57, c58, c59, c60, c61, c62, c63, c64, c65, c66, c67, c68, c69, c70, c71, c72, c73, c74, c75, c76, c77, c78, c79, c80, c81, c82, c83};

    Sound * s = new Sound();
    string player_turn; // 1 for Human turn, 0 for PC turn
    int bank_size;
    std::vector<int> m_BankEmptySlots{};
    vector <Card*>& human_deck;
    vector <Card*>& PC_deck;
    int spacing_pc;
    int placement_pc;
    int placement_human;
    int position_pc;
    int spacing_human;
    int position_human;
    
    // bool wild_screen;
    
    Card* prev_card;
    vector <Card*> Centre;
    vector <HiddenCards *> PC_Bank;
    bool draw_four_by_pc;
    bool wild_by_pc;
    bool wild_by_human;
    bool draw_four_by_human;
    string colour;
    bool colour_selected;
    string winner;
    
    public:
    


    // void add_card_bank(Card* card_to_add);
    void drawObjects(); 
    void Click(int, int);
    void PC_turn();
    void game_initialization();
    friend Card* operator - (UNO& obj, std::string val);
    friend void operator + (UNO& obj, Card* const card_to_add);
    static UNO& get_instance();
    void check_deck(vector <Card*> deck1, vector <Card*> deck2);
    void pick_from_bank(std::string deck);
    void wild_screen(int, int);
    void arrow_click(int x);
    void human_turn(int x, int y);
    void draw_four_applied(std::string victim);
    void wild_card_check (Card * card, string player);
    bool get_wild_by_human_signal();
    bool get_draw_four_by_human_signal();
    bool get_wild_by_pc_signal();
    bool get_draw_four_by_pc_signal();
    string get_winner();
    
    ~UNO();

    // create destructor which deletes all dynamic objects
};
