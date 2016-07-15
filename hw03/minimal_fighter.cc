// minimal_fighter.cc
// 2017. 7. 15

#include "minimal_fighter.h"

// default constructor;
MinimalFighter::MinimalFighter()
{
  mHp = 0;
  mPower = 0;
  mStatus = Invalid;
}


MinimalFighter::MinimalFighter(int _hp, int _power)
{
  mHp = _hp;
  mPower = _power;
  if(_hp <= 0)
  {
    mStatus = Dead;
  }
  else
  {
    mStatus = Alive;
  }
}

int MinimalFighter::hp() const
{
  return mHp;
}

int MinimalFighter::power() const
{
  return mPower;
}

FighterStatus MinimalFighter::status() const
{
  return mStatus;
}

// if _hp <= 0, change the mStatus also, and set mHp to 0;
void MinimalFighter::setHp(int _hp)
{
  if(_hp > 0)
  {
    mHp = _hp;
  }
  else
  {
    mHp = 0;
    mStatus = Dead;
  }
}

void MinimalFighter::hit(MinimalFighter *_enemy)
{
  _enemy->setHp(_enemy->hp() - this->power());
  this->setHp(this->hp() - _enemy->power());
}

void MinimalFighter::attack(MinimalFighter *_target)
{
  _target->setHp(_target->hp() - this->power());
  this->mPower = 0;
}

void MinimalFighter::fight(MinimalFighter *_enemy)
{
  while(this->mStatus == Alive && _enemy->mStatus == Alive)
  {
    this->hit(_enemy);
  }
}
