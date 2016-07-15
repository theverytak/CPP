// minimal_fighter.h
// 2017. 7. 15

#ifndef __hw03__minimal_fighter__
#define __hw03__minimal_fighter__

#include <iostream>
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

#endif

minimal_fighter.h
minimal_fighter.h 표시 중입니다.
