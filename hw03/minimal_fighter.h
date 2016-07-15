// minimal_fighter.h
// 2017. 7. 15

#ifndef _MINIMAL_FIGHTER_H_
#define _MINIMAL_FIGHTER_H_

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

enum EFighterStatus
{
    Invalid = 0,

    Alive,
    Dead,
};
typedef enum EFighterStatus FighterStatus;

class MinimalFighter
{
private:
    int mHp;
    int mPower;
    FighterStatus mStatus;

public:
    MinimalFighter();
    MinimalFighter(int _hp, int _power);

    int hp() const;
    int power() const;
    FighterStatus status() const;

    void setHp(int _hp);

    void hit(MinimalFighter *_enemy);
    void attack(MinimalFighter *_target);
    void fight(MinimalFighter *_enemy);
};

#endif // _MINIMAL_FIGHTER_H_
