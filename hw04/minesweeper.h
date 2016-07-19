// minesweeper.h
// 2017. 7. 19

#ifndef _MINESWEEPER_H_
#define _MINESWEEPER_H_

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Minesweeper
{
private:
    size_t mWidth, mHeight;
    vector<string> mMap;
    int mTouchCount;

public:
    ////////// 4-3-1 (7 score) //////////
    Minesweeper();
    ~Minesweeper();

    // return map width, height, char, map, and touchCount;
    size_t width() const;
    size_t height() const;
    int touchCount() const;
    vector<string> map() const;
    char get(int _x, int _y) const; // return ' ' if input is illegal

    // return false when input is incorrect
    bool setMap(size_t _width, size_t _height, vector<string>& _map);
    bool toggleMine(int _x, int _y);

    // print the map
    void printMap();
    ////////// 4-3-2 (3 score) //////////
    bool setPlay(); // return false when map is not set
    bool touchMap(int _x, int _y); // return true when dead

};

#endif // _MINESWEEPER_H_
