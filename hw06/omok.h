// omok.h
// 2016. 7. 28

#ifndef _OMOK_H_
#define _OMOK_H_

#define BLACK -1
#define NOBODY 0
#define WHITE 1
#define GROUND_SIZE 19
#include <iostream>
#include <vector>

using namespace std;

class Omok {
  public:
    Omok() : width_(GROUND_SIZE), height_(GROUND_SIZE), turn_(BLACK) {
      for(int i = 0; i < GROUND_SIZE; i++)
        ground_.push_back("...................");
    }

    // put stone at (x, y) by taking turn (x, y = 0 ~ 18).
    // assuming that first turn is black.
    // putting stone outside of the ground or already taken place return NOBODY.
    // normal case will put stone and adjust turn_ and return it.
    // but it will return this turn, not upcoming one.(first Put() will return BLACK)
    int Put(int x, int y);

    // change winner to adequate one(BLACK wins -> winner = BLACK)
    // if noone wins yet, winner will be NOBODY;
    void IsOmok(int* winner) const;

    // below 4 functions will return the number of stones in continue
    // according to the given directions;
    int CheckHorizon(int x, int y) const;
    int CheckVertical(int x, int y) const;
    int CheckDiagonalDown(int x, int y) const;
    int CheckDiagonalUp(int x, int y) const;

    int Turn() const { return turn_; }
    friend ostream& operator<<(ostream& os, const Omok& omok);
  private:
    int width_, height_;
    int turn_;  // save lately played player;
    vector<string> ground_;
};

// print omok ground;
ostream& operator<<(ostream& os, const Omok& omok);

#endif  // _OMOK_H_
