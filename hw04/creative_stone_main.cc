// creative_stone_main.cc
// 2017. 7. 20

#include "creative_stone.h"


int main()
{
  string command;
  CreativeStone cs;
  while(true)
  {
    cin >> command;
    if(command == ":add")
    {
      // add freind;
      string name;
      int hp, power;
      cin >> name >> hp >> power;
      if(cs.addMinion(true, name, hp, power))
      {
        cs.printMinions();
      }
    }
    else if(command == ":foeadd")
    {
      // add enemy;
      string name;
      int hp, power;
      cin >> name >> hp >> power;
      if(cs.addMinion(false, name, hp, power))
      {
        cs.printMinions();
      }
    }
    else if(command == ":attack")
    {
      string name1, name2;
      cin >> name1 >> name2;
      if(cs.attack(name1, name2))
      {
        cs.printMinions();
      }
    }
    else if(command == ":burn")
    {
      string name;
      cin >> name;
      if(!isdigit(name[0]))
      {
        // if name is a string -> input a number and burn specific minion;
        int burningPower;
        cin >> burningPower;
        if(cs.burnTarget(name, burningPower))
        {
          cs.printMinions();
        }
      }
      else // name is not a stirng -> burn all;
      {
        // change name to a int;
        string::size_type sz;
        int burningPower = stoi(name, &sz);
        if(cs.burnAll(burningPower))
        {
          cs.printMinions();
        }
      }
    }
    else
    {
      break;
    }
  }
  return 0;
}
