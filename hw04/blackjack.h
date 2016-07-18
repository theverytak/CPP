// blackjack.h
// 2017. 7. 18

#ifndef _BLACKJACK_H_
#define _BLACKJACK_H_

#include <iostream>
#include <string>
using namespace std;

bool validCardInput(const string* , const int& );
bool validNumInput(const int& );

class Blackjack
{
  private:
    int mCardNum;
    string* mCards;

  public:
    Blackjack();
    Blackjack(const int _cardNum, const string* _cards);
    ~Blackjack();
    int cardNum() const;
    string* cards() const;
    int dealer() const;
};

#endif  // _BLACKJACK_H_
