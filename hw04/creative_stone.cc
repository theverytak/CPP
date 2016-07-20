// creative_stone.cc
// 2017. 7. 20

#include "creative_stone.h"


map<string, Minion> CreativeStone::friends() const
{
  return mFriends;
}
map<string, Minion> CreativeStone::enemies() const
{
  return mEnemies;
}

bool CreativeStone::addMinion(const bool _friend, const string _name,
                              const int _hp, const int _power)
{
  if(_friend)
  {
    // add mFriends;
    if(friends().find(_name) == friends().end())
    {
      // new minion;
      if(_hp <= 0)
      {
        return false;
      }
      mFriends.insert(pair<string, Minion>(_name, Minion(_hp, _power)));
      if(friends()[_name].power() < 0)
      {
        mFriends[_name].setPower(0);
      }
      return true;
    }
    else
    {
      // already existed minion;
      mFriends[_name].setHp(mFriends[_name].hp() + _hp);
      mFriends[_name].setPower(mFriends[_name].power() + _power);
      if(friends()[_name].hp() <= 0)
      {
        mFriends.erase(_name);
        return false;
      }
      else if(friends()[_name].power() <= 0)
      {
        mFriends[_name].setPower(0);
      }
      return true;
    }
  }
  else
  {
    // add mEnemies;
    if(enemies().find(_name) == enemies().end())
    {
      // new minion;
      if(_hp <= 0)
      {
        return false;
      }
      mEnemies.insert(pair<string, Minion>(_name, Minion(_hp, _power)));
      if(enemies()[_name].power() < 0)
      {
        mEnemies[_name].setPower(0);
      }
      return true;
    }
    else
    {
      // already existed minion;
      mEnemies[_name].setHp(mEnemies[_name].hp() + _hp);
      mEnemies[_name].setPower(mEnemies[_name].power() + _power);
      if(enemies()[_name].hp() <= 0)
      {
        mEnemies.erase(_name);
        return false;
      }
      else if(enemies()[_name].power() <= 0)
      {
        mEnemies[_name].setPower(0);
      }
      return true;
    }
  }
}

bool CreativeStone::attack(const string _name1, const string _name2)
{
  if(friends().find(_name1) == friends().end() ||
     enemies().find(_name2) == enemies().end())
  {
      // no minions named _name1 or _name2;
    cout << "CANNOT FIND MINION" << endl;
    return false;
  }
  // attack each other;
  // ********error will be here **************
  mEnemies[_name2].setHp(mEnemies[_name2].hp() - friends()[_name1].power());
  mFriends[_name1].setHp(mFriends[_name1].hp() - enemies()[_name2].power());

  // if hp <= 0, erase minions;
  if(enemies()[_name2].hp() <= 0)
  {
    mEnemies.erase(_name2);
  }
  if(friends()[_name1].hp() <= 0)
  {
    mFriends.erase(_name1);
  }

  return true;
}

bool CreativeStone::burnTarget(const string _name, const int _burningPower)
{
  // if theres a enemy minion named _name;
  if(_burningPower < 0)
  {
    return false;
  }
  if(mEnemies.find(_name) != mEnemies.end())
  {
    mEnemies[_name].setHp(mEnemies[_name].hp() - _burningPower);
    if(mEnemies[_name].hp() <= 0)
    {
      mEnemies.erase(_name);
      return true;
    }
  }
  // if theres a freind minion, not among enemies, named _name;
  else if(mFriends.find(_name) != mFriends.end())
  {
    mFriends[_name].setHp(mFriends[_name].hp() - _burningPower);
    if(mFriends[_name].hp() <= 0)
    {
      mFriends.erase(_name);
      return true;
    }
  }
  // no minions named _name among friends and enemies;
  else
  {
    cout << "CANNOT FIND MINION" << endl;
    return false;
  }
}

bool CreativeStone::burnAll(const int _burningPower)
{
  if(_burningPower < 0)
  {
    return false;
  }
  // for all enemy minions, burn;
  for(auto it = mEnemies.begin(); it != mEnemies.end(); it++)
  {
    it->second.setHp(it->second.hp() - _burningPower);
    if(it->second.hp() <= 0)
    {
      mEnemies.erase(it);
    }
  }
  return true;
}

void CreativeStone::printMinions()
{
  for(auto itF = mFriends.begin(), itE = mEnemies.begin();
      itF != mFriends.end() || itE != mEnemies.end(); )
  {
    if(!mFriends.empty() && itF != mFriends.end())
    {
      cout << itF->first << " " << itF->second.hp() << " " <<
              itF->second.power();
      itF++;
    }
    if(!mEnemies.empty() && itE != mEnemies.end())
    {
      cout << " / " << itE->first << " " << itE->second.hp() << " " <<
              itE->second.power() << endl;
      itE++;
    }
    else
    {
      cout << endl;
    }
  }
  /*for(auto it = mEnemies.begin(); it != mEnemies.end(); it++)
  {
    cout << it->first << " " << it->second.hp() << " " <<
            it->second.power() << endl;
  }
  cout << "for loop ends here" << endl;
  for(auto it = mFriends.begin(); it != mFriends.end(); it++)
  {
    cout << it->first << " " << it->second.hp() << " " <<
            it->second.power() << endl;
  }
  cout << "for loop ends here again" << endl;  */
}
