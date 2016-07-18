// blackjack.cc
// 2017. 7. 18

#include "blackjack.h"


// check if the input card is a valid one;
bool validCardInput(const string* inputCards, const int& index)
{
  if(inputCards[index][0] >= '2' && inputCards[index][0] <= '9')
  {
    return true;
  }
  else if(inputCards[index] == "A" || inputCards[index] == "J" || inputCards[index] == "10" ||
          inputCards[index] == "Q" || inputCards[index] == "K")
  {
    return true;
  }
  else
  {
    return false;
  }
}

// check if the input number is valid(a number bigger than or same as 2);
bool validNumInput(const int& inputNum)
{
  if(inputNum >= 2)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// constructors and destructor
Blackjack::Blackjack()
{
  mCardNum = 0;
  mCards = NULL;
}
Blackjack::Blackjack(const int _cardNum, const string* _cards)
{
  mCardNum = _cardNum;
  mCards = new string[_cardNum];
  for(int i = 0; i < _cardNum; i++)
  {
    mCards[i] = _cards[i];
  }
}
Blackjack::~Blackjack()
{
  delete[] mCards;
}

// return private member valiation;
int Blackjack::cardNum() const
{
  return mCardNum;
}
string* Blackjack::cards() const
{
  return mCards;
}

// find the result of the blackjack;
int Blackjack::dealer() const
{
  // aceNum for the number of 'A' in the cards, result for return,
  // assumedResult for the result in the case of calculating 'A' == 11;
  int aceNum = 0;
  int result = 0;
  int assumedResult = 0;

  // find aceNum, result;
  for(int i = 0; i < cardNum(); i++)
  {
    if(cards()[i] == "A")
    {
      aceNum++;
    }
    else if(cards()[i][0] >= '2' && cards()[i][0] <= '9')
    {
      result += cards()[i][0] - '0';
    }
    else if(cards()[i] == "10" || cards()[i] == "J" || cards()[i] == "Q" ||
            cards()[i] == "K")
    {
      result += 10;
    }
  }

  // decide if 'A' is 11 or 1;
  while(assumedResult < 21 && aceNum >= 0)
  {
    // assume that one of the ace is 11. So the aceNum decreases;
    if(aceNum == 0)
    {
      assumedResult = result;
    }
    else
    {
    assumedResult = result + 11 * (aceNum > 0) + (aceNum - 1);
    }

    if(assumedResult > 21)
    {
      return result + aceNum;
    }
    else
    {
      result += 11 * (aceNum > 0);
      aceNum--;
    }
  }
  return result;
}
