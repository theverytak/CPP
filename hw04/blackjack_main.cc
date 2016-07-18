// blackjack_main.cc
// 2017. 7. 18

#include "blackjack.h"

int main()
{
  int inputNum;
  string* inputCards;
  int result;

  while(true)
  {

    // input number of cards and the actual cards;
    // if number of any cards input was wrong, exit the program immediately;
    cin >> inputNum;
    if(!validNumInput(inputNum))
    {
      return 0;
    }
    inputCards = new string[inputNum];
    for(int i = 0; i < inputNum; i++)
    {
      cin >> inputCards[i];
      if(!validCardInput(inputCards, i))
      {
        return 0;
      }
    }

    // make a blackjack class and delete the inputCards array. Then find
    // if its blackjack or not;
    Blackjack blackjack(inputNum, inputCards);
    delete[] inputCards;
    result = blackjack.dealer();

    if(result == 21)
    {
      cout << "BlackJack" << endl;
    }
    else if(result < 21)
    {
      cout << result << endl;
    }
    else
    {
      cout << "Exceed" << endl;
    }
  }
}
