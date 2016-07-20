// creative_stone.h
// 2017. 7. 20

#ifndef _CREATIVE_STONE_H_
#define _CREATIVE_STONE_H_
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Minion
{
  private :
    int mHp;
    int mPower;

  public :
    Minion() { mHp = 0; mPower = 0; }
    Minion(int hp, int power) { mHp = hp; mPower = power; }
    int hp() const { return mHp; }
    int power() const { return mPower; }
    void setHp(int _hp) { mHp = _hp; }
    void setPower(int _power) { mPower = _power; }
};

class CreativeStone
{
  private :
    map<string, Minion> mFriends;
    map<string, Minion> mEnemies;

  public :
    map<string, Minion> friends() const;
    map<string, Minion> enemies() const;
    bool addMinion(const bool _friend, const string _name,
                   const int _hp, const int _power);
    bool burnTarget(const string _name, const int _burningPower);
    bool burnAll(const int _burningPower);
    bool attack(const string _name1, const string _name2);
    void printMinions();
};


#endif //_CREATIVE_STONE_H_
