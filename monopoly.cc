#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

int MAX_LINE_SIZE = 1024;

int roll_dice();

class Player
{
  int money;
  Player(): money(0)
  {
  }
  void add_money(int amt)
  {
    money += amt;
  }
};
class Menu;

class Board
{
  public:
    Board();
    vector<Player*> players;

};

Board::Board()
{
  srand(time(NULL));

}

class Menu_item
{
   public:
    const char* prompt;
    virtual void handle(Board* m) = 0;
};

class Roll_dice_item: public Menu_item
{
  public:
    Roll_dice_item():Menu_item()
    {
      prompt = "Roll the dice";
    }

    void handle(Board* m);
};

class Report_money_item: public Menu_item
{
  public:
    Report_money_item():Menu_item()
    {
      prompt = "Report the player's current money";
    }

    void handle(Board* m);
};

class Add_money_item: public Menu_item
{
  public:
    Add_money_item():Menu_item()
    {
      prompt = "Add money";
    }

    void handle(Board* m);
};

class Spend_money_item: public Menu_item
{
  public:
    Spend_money_item():Menu_item()
    {
      prompt = "Spend money";
    }

    void handle(Board* m);
};

class Pass_GO_item: public Menu_item
{
  public:
    Pass_GO_item():Menu_item()
    {
      prompt = "Pass GO";
    }

    void handle(Board* m);
};

class Buy_property_item: public Menu_item
{
  public:
    Buy_property_item():Menu_item()
    {
      prompt = "Buy property";
    }

   void handle(Board* m);
};

class Sell_property_item: public Menu_item
{
  public:
    Sell_property_item():Menu_item()
    {
      prompt = "Sell property";
    }

   void handle(Board* m);
};

class Display_owned_properties_item: public Menu_item
{
  public:
    Display_owned_properties_item():Menu_item()
    {
      prompt = "Display owned properties";
    }

   void handle(Board* m);
};

class Quit_program_item: public Menu_item
{
  public:
    Quit_program_item():Menu_item()
    {
      prompt = "Quit program";
    }

   void handle(Board* m);
};



class Menu
{
public:
  vector<Menu_item*> items;

  void display();
  void add_item(Menu_item* it)
  {
    items.push_back(it);
  }
};

void Menu::display()
{
  for(int i=0; i < items.size(); i++)
  {
    cout << (i+1) << ") "   <<   items[i]->prompt << endl;
  }

  for(;;)
  {
    cout << "Enter your selection: " << flush;

    int choice;

    if(!(cin >> choice))
    {
      cout << "Please enter an integer." << endl;
      cin.clear();
      cin.ignore(MAX_LINE_SIZE,'\n');
      continue;
    }

    if (choice < 1|| choice > items.size())
    {
      cout << "Invalid selection" << endl;
      continue;
    }

     Menu_item* it = items[choice-1];
     it->handle(NULL);

  }
}
int roll_dice()
{
  return rand() % 6+1;
}
void Roll_dice_item::handle(Board* m)
{
  cout << "Rolling dice." << endl;
  cout << roll_dice() + roll_dice() << endl;
}

void Report_money_item::handle(Board* m)
{
  cout << "Reporting money." << endl;
}

void Add_money_item::handle(Board* m)
{
  cout << "Adding money." << endl;
}

void Spend_money_item::handle(Board* m)
{
  cout << "Spending money." << endl;
}

void Pass_GO_item::handle(Board* m)
{
  cout << "Passing GO." << endl;
}

void Buy_property_item::handle(Board* m)
{
  cout << "Buying property."<< endl;
}

void Sell_property_item::handle(Board* m)
{
  cout << "Selling property."<< endl;
}

void Display_owned_properties_item::handle(Board* m)
{
  cout << "Displaying properties."<< endl;
}

void Quit_program_item::handle(Board* m)
{
  cout << "Quitting program."<< endl;
  exit(0);
}


/*void test_menu_items()
{
  Roll_dice_item dit;
  dit.handle(NULL);
  Report_money_item mit;
  mit.handle(NULL);
  Add_money_item ait;
  ait.handle(NULL);
  Spend_money_item sit;
  sit.handle(NULL);
  Pass_GO_item git;
  git.handle(NULL);
  Buy_property_item bit;
  bit.handle(NULL);
  Sell_property_item pit;
  pit.handle(NULL);
  Display_owned_properties_item oit;
  oit.handle(NULL);
  Quit_program_item qit;
  qit.handle(NULL);

}*/

void test_input()
{
   string dummy;
 // test_menu_items();
  cout << "Please enter an integer value: ";
  while(1)
  {
  int i = 0;
  if (cin >> i)
  {
   cout << "The value you entered is " << i;
   cout << " and its double is " << i*2 << ".\n";
  }
  else {
    cin.clear();
    cin >> dummy;
    cout << "Please enter an integer value: ";
       }
  }
}

int main(int argc, char** argv)
{
  Menu menu;
  menu.add_item( new Roll_dice_item());
  menu.add_item( new Report_money_item());
  menu.add_item( new Add_money_item());
  menu.add_item( new Spend_money_item());
  menu.add_item( new Pass_GO_item());
  menu.add_item( new Buy_property_item());
  menu.add_item( new Sell_property_item());
  menu.add_item( new Display_owned_properties_item());
  menu.add_item( new Quit_program_item());
  menu.display();
  return 0;
}

