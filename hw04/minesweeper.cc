// minesweeper.cc
// 2017. 7. 19

#include "minesweeper.h"


Point::Point(int _x, int _y)
{
  x = _x;
  y = _y;
}

bool Point::operator==(const Point& rhs) const
{
  return (this->x == rhs.x && this->y == rhs.y);
}

// constructor and destructor
Minesweeper::Minesweeper()
{
  mWidth = 0;
  mHeight = 0;
  mTouchCount = 0;
  isPlaying = false;
}
Minesweeper::~Minesweeper() {}

size_t Minesweeper::width() const
{
  return mWidth;
}
size_t Minesweeper::height() const
{
  return mHeight;
}
int Minesweeper::touchCount() const
{
  return mTouchCount;
}
vector<string> Minesweeper::map() const
{
  return mMap;
}
vector<Point> Minesweeper::touch() const
{
  return mTouch;
}

char Minesweeper::get(int _x, int _y) const
{
  if(_y < 0 || _y >= this->map().size())
  {
    return ' ';
  }
  if(_x < 0 || _x >= this->map()[_y].size())
  {
    return ' ';
  }

  // return '*' if it's a mine itself;
  if(map()[_y][_x] == '*')
  {
    return '*';
  }

  // if it's not a mine, return number;
  int count = 0;
  // theres total 9 cases. on the each point, on the each side, and inside;
  if(_y == 0 && _x == 0)
  {
    // top left pt;
    count += (map()[_y][_x + 1] == '*');  // right
    count += (map()[_y + 1][_x] == '*');  // down
    count += (map()[_y+ 1][_x + 1] == '*'); // right and down
  }
  else if(_y == 0 && _x == this->map()[_y].size() - 1)
  {
    // top right pt;
    count += (map()[_y][_x - 1] == '*');  // left
    count += (map()[_y + 1][_x] == '*');  // down
    count += (map()[_y + 1][_x - 1] == '*'); // left and down
  }
  else if(_y == this->map().size() - 1 && _x == 0)
  {
    // bottom left pt;
    count += (map()[_y][_x + 1] == '*');  // right
    count += (map()[_y - 1][_x] == '*');  // up
    count += (map()[_y - 1][_x + 1] == '*'); // right and up
  }
  else if(_y == this->map().size()  - 1 && _x == this->map()[_y].size() - 1)
  {
    // bottom right pt;
    count += (map()[_y][_x - 1] == '*');  // left
    count += (map()[_y - 1][_x] == '*');  // up
    count += (map()[_y - 1][_x - 1] == '*'); // left and up
  }
  else if(_y == 0)
  {
    // top side;
    count += (map()[_y + 1][_x] == '*');  // down
    count += (map()[_y][_x - 1] == '*');  // left
    count += (map()[_y][_x + 1] == '*');  // right
    count += (map()[_y + 1][_x - 1] == '*'); // left and down
    count += (map()[_y+ 1][_x + 1] == '*'); // right and down
  }
  else if(_y == this->map().size() - 1)
  {
    // bottom side;
    count += (map()[_y - 1][_x] == '*');  // up
    count += (map()[_y][_x - 1] == '*');  // left
    count += (map()[_y][_x + 1] == '*');  // right
    count += (map()[_y - 1][_x + 1] == '*'); // right and up
    count += (map()[_y - 1][_x - 1] == '*'); // left and up
  }
  else if(_x == 0)
  {
    // left side;
    count += (map()[_y - 1][_x] == '*');  // up
    count += (map()[_y + 1][_x] == '*');  // down
    count += (map()[_y][_x + 1] == '*');  // right
    count += (map()[_y - 1][_x + 1] == '*'); // right and up
    count += (map()[_y+ 1][_x + 1] == '*'); // right and down
  }
  else if(_x == this->map()[_y].size() - 1)
  {
    // right side;
    count += (map()[_y - 1][_x] == '*');  // up
    count += (map()[_y + 1][_x] == '*');  // down
    count += (map()[_y][_x - 1] == '*');  // left
    count += (map()[_y - 1][_x - 1] == '*'); // left and up
    count += (map()[_y + 1][_x - 1] == '*'); // left and down
  }
  else
  {
    // inside
    count += (map()[_y - 1][_x] == '*');  // up
    count += (map()[_y + 1][_x] == '*');  // down
    count += (map()[_y][_x - 1] == '*');  // left
    count += (map()[_y][_x + 1] == '*');  // right
    count += (map()[_y - 1][_x - 1] == '*'); // left and up
    count += (map()[_y + 1][_x - 1] == '*'); // left and down
    count += (map()[_y - 1][_x + 1] == '*'); // right and up
    count += (map()[_y+ 1][_x + 1] == '*'); // right and down
  }

  return count + '0';
}

bool Minesweeper::setMap(size_t _width, size_t _height, vector<string>& _map)
{
  if(_width < 0 || _height < 0)
  {
    return false;
  }

  mWidth = _width;
  mHeight = _height;
  mMap = _map;
  isPlaying = false;
  mTouch.clear();

  return true;
}

bool Minesweeper::toggleMine(int _x, int _y)
{
  if( _y < 0 || _x < 0 ||
      _y >= this->map().size() || _x >= this->map()[_y].size())
  {
    return false;
  }

  // if (_x, _y) is a mine, change it to a dot. Then change it to
  // a number using get();
  if(get(_x, _y) == '*')
  {
    mMap[_y][_x] = '.';
  }

  else
  {
    mMap[_y][_x] = '*';
  }

  return true;
}

void Minesweeper::printMap()
{
  if(!isPlaying)
  {
    for(int i = 0; i < height(); i++)
    {
      for(int j = 0; j < width(); j++)
      {
        cout << get(j ,i);
      }
      cout << endl;
    }
  }
  else
  {
    for(int i = 0; i < height(); i++)
    {
      for(int j = 0; j < width(); j++)
      {
        Point pt(j, i);
        vector<Point>::iterator it = find(mTouch.begin(), mTouch.end(), pt);
        if(it != mTouch.end())
        {
          cout << get(j, i);
        }
        else
        {
          cout << '_';
        }
      }
      cout << endl;
    }
  }
}

bool Minesweeper::setPlay()
{
  if(this->map().empty())
  {
    return false;
  }
  else
  {
    isPlaying = true;
  }
  return true;
}

bool Minesweeper::touchMap(int _x, int _y)
{
  if(get(_x, _y) == '*')
  {
    mTouchCount++;
    return true;
  }
  else
  {
    Point touched(_x,_y);
    vector<Point>::iterator it = find(mTouch.begin(), mTouch.end(), touched);
    if(it != mTouch.end())
    {
      return false;
    }
    mTouch.push_back(touched);
    mTouchCount++;
    return false;
  }
}
