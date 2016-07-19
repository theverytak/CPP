// minesweeper_main.cc
// 2017. 7. 19

#include "minesweeper.h"

int main()
{
  string command;
  size_t width, height;
  int col, row;
  vector<string> map;
  Minesweeper m;

  while(true)
  {
    cin >> command;
    if(command == ":set")
    {
      map.clear();
      cin >> width >> height;
      for(int i = 0; i < height; i++)
      {
        string str;
        cin >> str;
        map.push_back(str);
      }
      m.setMap(width, height, map);
      m.printMap();
    }
    else if(command == ":toggle")
    {
      cin >> col >> row;
      m.toggleMine(col, row);
      m.printMap();
    }
    else if(command == ":play")
    {
      m.setPlay();
      m.printMap();
    }
    else if(command == ":touch")
    {
      cin >> col >> row;
      m.touchMap(col, row);
      m.printMap();
    }
    else
    {
      break;
    }
  }
  return 0;
}
