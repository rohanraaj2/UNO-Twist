// #include <iostream>
#include "UNO.hpp"

using namespace std;

Human human_player ("humanplayer", 8);   
PC PC_player ("PCplayer", 8);


  
UNO::UNO ():  human_deck {human_player.get_deck()} ,PC_deck {PC_player.get_deck()}
 // making the construct private to avoid making more than one object
{
  placement_pc = 300;
  position_pc = placement_pc + spacing_pc;

  placement_human = 150;
  position_human = 150 + spacing_human;
  
  player_turn = 1; // 1 for Human turn, 0 for PC turn
  bank_size = 79;
  draw_four_by_human = false;
  wild_by_human = false;
  wild_by_pc = false;
  draw_four_by_pc = false;
  colour_selected = false;

  string winner = "No one";
}

// UNO:: UNO(const UNO& ob) // making the copy constructor private to avoid accidentally creating a constructor in the main
// {
// // human_deck = human_player.get_deck(); 
// //   PC_deck = PC_player.get_deck();
// }


UNO& UNO::get_instance() // making a function public so that we can make the object, but static will ensure that we make only one object
{
  static UNO obj;

  return obj;
}

void UNO::game_initialization()
{
  Card* temp;

  for(int x = 0; x <= 7; x++) // populating human deck
  {
    temp = (*this)-"card";
    human_player.pick_card(temp);
  }
  for(int x = 0; x <= 7; x++) // populating player deck
  {
    temp = (*this)-"card";
    PC_player.pick_card(temp);
    PC_Bank.push_back(new HiddenCards {"Small"});
  }

  // human_deck = human_player.get_deck(); 
  // PC_deck = PC_player.get_deck();
  
  Card* temp_card;
  temp_card = (*this) - "card";
  if (temp_card->GetCardId() == "NC")
  {
    (*this) + temp_card;
    temp_card = c6;
    m_bank[6] = nullptr;
  }
  temp_card->g.set_mover_rect_x(870);
  Centre.push_back(temp_card);
  prev_card = temp_card;
}

void UNO::drawObjects()
{
  right_most_card_of_bank.g.draw(900, 230);
  a9.g.draw(895, 230);
  a10.g.draw(890, 230);
  a11.g.draw(885, 230);
  a12.g.draw(880, 230);
  a13.g.draw(875, 230);
  a14.g.draw(870, 230);
  left_most_card_of_bank.g.draw(865, 230);
 
  spacing_pc = 50 * (7 - PC_Bank.size());
  spacing_human = 50 * (7 - human_deck.size());

  for(int i = 0; i < PC_deck.size(); i++)
  {
    PC_Bank[i]->g.draw(position_pc + (50 * i), 50);
  }

  // position_human = 150 + spacing_human;
  for(int i = 0; i < human_deck.size(); i++)
  {
    human_deck[i]->g.draw(position_human + spacing_human + (100 * i), 410);
  }
  for(int i = 0; i < Centre.size(); i++)
  {
    if (i == 0)
    {
      if (Centre[i]->g.get_mover_rect().x > 450)
      {
        Centre[i]->g.set_mover_rect_x(Centre[i]->g.get_mover_rect().x - 20);
      }
      Centre[i]->g.draw(Centre[i]->g.get_mover_rect().x, 230);
    }
    else
    {
      if (Centre[i - 1]->g.get_mover_rect().x == 450 && Centre[i - 1]->g.get_mover_rect().y == 230)
      {
        if (Centre[i]->g.get_mover_rect().y > 230)
        {
          Centre[i]->g.set_mover_rect_y(Centre[i]->g.get_mover_rect().y - 20);
        }
        else if (Centre[i]->g.get_mover_rect().y < 230)
        {
          Centre[i]->g.set_mover_rect_y(Centre[i]->g.get_mover_rect().y + 20);
        }
        Centre[i]->g.draw(450, Centre[i]->g.get_mover_rect().y);
      }
    }
  }
}

void UNO::check_deck(vector <Card*> deck1, vector <Card*> deck2)
{
  if(deck1.empty() == true)
  {
    winner = "PC";
  }
  else if(deck2.empty() == true)
  {
    winner = "Human";
  }
}

void UNO::wild_screen(int x, int y)
{
  std::cout<<"in wild function";
  if (wild_by_human || draw_four_by_human)
  {
    if (y >= 402 && y <= 583)
      {
        if (x >= 561 && x <= 917)
        {
          colour = "Green";
          colour_selected = true;
        }
        else if (x >= 101 && x <= 439)
        {
          colour = "Blue";
          colour_selected = true;
        }
      }
      else if (y >= 196 && y <= 381)
      {
        if (x >= 561 && x <= 917)
        {
          colour = "Yellow";
          colour_selected = true;
        }
        else if (x >= 101 && x <= 439)
        {
          colour = "Red";
          colour_selected = true;
        }
      }
      cout << colour << endl;
      if (colour_selected)
      {
        draw_four_by_human = false;
        wild_by_human = false;
        PC_turn();

      }

  }
}

void UNO::arrow_click(int x)
{
  if (x >= 7 && x <= 76 && (human_deck[0]->g.get_mover_rect().x < 0))
  {
    position_human += 70;
  }
  else if (x >= 917 && x <= 986 && (human_deck[human_deck.size() - 1]->g.get_mover_rect().x > (1000 - human_deck[human_deck.size() - 1]->g.get_mover_rect().w)))
  {
    position_human -= 70;
  }
}

void UNO::pick_from_bank(std::string deck)
{
  Card* card_picked;
  card_picked = (*this) - "card";
  if (deck == "human_deck")
  {
    human_player.pick_card(card_picked);
    // human_deck.push_back(card_picked);
    // while (human_deck[human_deck.size() - 1]->g.get_mover_rect().x > (1000 - human_deck[human_deck.size() - 1]->g.get_mover_rect().w))
    // {
    //   position_human -= 70;
    // }
    // if (human_deck.size() > 10)
    // {
    //   position_human -= 70;
    // }
  }
  else if (deck == "PC_deck")
  {
    // PC_deck.push_back(card_picked);
    PC_player.pick_card(card_picked);
    PC_Bank.push_back(new HiddenCards {"Small"});

  }
  s->pick_card(true);
  
}

void UNO::wild_card_check (Card * card, string player)
{
  if (card == c76 || card == c77 || card == c78 || card == c79)
  {
    if (player == "Human")
    {
      draw_four_by_human = true;

    }
    else if (player == "PC")
    {
      draw_four_by_pc = true;
    }
    std::cout<< "It is a wild card";

  }
  else if (card == c80 || card == c81 || card == c82 || card == c83)
  {
    if (player == "Human")
    {
      wild_by_human = true;
      // return "Wild by Human";
    }
    else if (player == "PC")
    {
      wild_by_pc = true;
      // return "Wild by PC";
    }
  }
}

void UNO::draw_four_applied(std::string victim)
{
  for(int i=0; i<=3; i++)
  {
    Card* temp_card;
    temp_card = (*this) - "card";
    if (victim == "human_deck")
    {
      human_player.pick_card(temp_card); // Card pushing in PC deck once Draw 4 dropped by Human.
    }
    else if (victim == "PC_deck")
    {
      PC_player.pick_card(temp_card); // Card pushing in PC deck once Draw 4 dropped by Human.
      PC_Bank.push_back(new HiddenCards {"Small"});

    }
    s->pick_card(true);
  }
}



void UNO::human_turn(int x, int y)
{
  for(int i = 0; i < human_deck.size(); i++) 
    {
      if (x >= human_deck[i]->g.get_mover_rect().x && x <= (human_deck[i]->g.get_mover_rect().x + human_deck[i]->g.get_mover_rect().w) 
      && y >= human_deck[i]->g.get_mover_rect().y && y <= (human_deck[i]->g.get_mover_rect().y + human_deck[i]->g.get_mover_rect().h))
      {
        // Card droping and Card adding implementation for Human.
        std::cout<<"For Human:\n"; 
        std::cout<<prev_card<<"<- prev card. s\n";
        std::cout<<colour<<"in human turn func \n";
        Card* temp = human_player.drop_card(human_deck[i], prev_card, colour);
        std::cout<<temp<<"<- temp card. s\n";

        if (temp != nullptr)
        {
          prev_card = temp;
          s->pick_card(true);
          Centre.push_back(prev_card);

          wild_card_check(prev_card, "Human");

          if (wild_by_human || draw_four_by_human)
          {            
            if (draw_four_by_human)
            {
              if (human_deck[i]->g.get_mover_rect().x == 450 && human_deck[i]->g.get_mover_rect().y == 230)
                {
                  draw_four_applied("PC_deck");
                }
            }

          }


          else
          {
            PC_turn();
          }
          // return;
          break;
          // player_turn = "PC";
        }
        else
        {
          std::cout<<"CLICK ON A VALID CARD.";
          break;
          // return;
        }
      }
    }
}

void UNO::PC_turn()
{
  Card * temp;
  std::cout<<"For PC:\n"; 
  std::cout<<prev_card<<"<- prev card. s\n";
  temp = PC_player.drop_card(nullptr, prev_card, colour); //set to nullptr because PC has its own algorithm to throw card and backend.
  std::cout<<temp<<"<- temp card. s\n";

  if (temp != nullptr)
  {
    prev_card = temp;
    s->pick_card(true);
    prev_card->g.set_mover_rect_y(50);

    Centre.push_back(prev_card);

    position_pc += 24.5;
    
    wild_card_check(prev_card, "PC");
    if (wild_by_pc || draw_four_by_pc)
    { 
      if (draw_four_by_pc)
      {
        if (prev_card->g.get_mover_rect().x == 450 && prev_card->g.get_mover_rect().y == 230)
        {
          draw_four_applied("human_deck");
        }
      }
      colour = PC_player.choose_wild_color();
      std::cout<<"The color PC has choosen: "<<colour;
    } 
  check_deck(PC_deck, human_deck);
  }
  else
  {
    pick_from_bank("PC_deck");
  }
  // return;
}       

void UNO::Click(int x, int y)
{
  
  if (wild_by_human || draw_four_by_human)
  {
    wild_screen (x, y);
  }
  else
  {

    if (x >= left_most_card_of_bank.g.get_mover_rect().x && x <= (right_most_card_of_bank.g.get_mover_rect().x + right_most_card_of_bank.g.get_mover_rect().w) 
      && y >= left_most_card_of_bank.g.get_mover_rect().y && y <= (right_most_card_of_bank.g.get_mover_rect().y + right_most_card_of_bank.g.get_mover_rect().h)) // picking from bank
    {
      pick_from_bank("human_deck");
      PC_turn();
    }
    else if (y >= 529 && y <= 579) //arrows
    {
      arrow_click(x);
    }
    else
    {
      human_turn(x, y);
      check_deck(PC_deck, human_deck);
    }

  }
}

Card* operator - (UNO& obj, std::string val)
// Card* UNO::get_card_bank()
{
  if (val == "card")
  {
    int c;
    Card* bank_card;
    srand((unsigned) time(NULL));
    c = 1+((rand() % obj.bank_size));
    while ( obj.m_bank[c]==nullptr )
    {
      c = 1+((rand() % obj.bank_size));
    }
    bank_card = obj.m_bank[c];
    obj.m_bank[c] = nullptr;
    obj.m_BankEmptySlots.push_back(c);
    return bank_card; 
  }

  else 
  {
    std::cout<<"Please enter correct spelling: 'card' ";
    return nullptr;
  }
}

void operator + (UNO& obj, Card* const card_to_add)
// void UNO::add_card_bank(Card* card_to_add)
{
  int p;
  p = obj.m_BankEmptySlots.back();
  obj.m_BankEmptySlots.pop_back();
  if (p!=0)
  {
    obj.m_bank[p] = card_to_add;
    cout<<"\nCard added successfully.\n";
  }
  else
  {
    cout<<"\nNo space is empty in Bank to fill in a card.\n";
  }
}

bool UNO::get_wild_by_human_signal()
{
  return wild_by_human;
}

bool UNO::get_draw_four_by_human_signal()
{
  return draw_four_by_human;
}

bool UNO::get_wild_by_pc_signal()
{
  return wild_by_pc;
}

bool UNO::get_draw_four_by_pc_signal()
{
  return draw_four_by_pc;
}

string UNO::get_winner()
{
  return winner;
}

// UNO::~UNO()
// {
// }

UNO::~UNO() // destructor
{   
    delete c0;
    delete c1;
    delete c2;
    delete c3;
    delete c5;
    delete c6;
    delete c7;
    delete c8;
    delete c9;
    delete c10;
    delete c11;
    delete c12;
    delete c13;
    delete c14;
    delete c15;
    delete c16;
    delete c17;
    delete c18;
    delete c19;
    delete c20;
    delete c21;
    delete c22;
    delete c23;
    delete c24;
    delete c25;
    delete c26;
    delete c27;
    delete c28;
    delete c29;
    delete c30;
    delete c31;
    delete c32;
    delete c33;
    delete c34;
    delete c35;
    delete c36;
    delete c37;
    delete c38;
    delete c39;
    delete c40;
    delete c41;
    delete c42;
    delete c43;
    delete c44;
    delete c45;
    delete c46;
    delete c47;
    delete c48;
    delete c49;
    delete c50;
    delete c51;
    delete c52;
    delete c53;
    delete c54;
    delete c55;
    delete c56;
    delete c57;
    delete c58;
    delete c59;
    delete c60;
    delete c61;
    delete c62;
    delete c63;
    delete c64;
    delete c65;
    delete c66;
    delete c67;
    delete c68;
    delete c69;
    delete c70;
    delete c71;
    delete c72;
    delete c73;
    delete c74;
    delete c75;
    delete c76;
    delete c77;
    delete c78;
    delete c79;
    delete c80;
    delete c81;
    delete c82;
    delete c83;

    delete s;
}
