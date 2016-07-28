// omok_main.cc
// 2016. 7. 28

#include "omok.h"

int main() {
  Omok omok;
  int winner = NOBODY;
  while(winner == NOBODY) {
    if(omok.Turn() == BLACK)
      cout << "Black: ";
    else
      cout << "White: ";

    // input x, y then put the stone
    // if there's error, restart the while loop.
    int x, y;
    cin >> x >> y;

    if(x == -1)
      return 0;

    if(omok.Put(x, y) == NOBODY) {
      cout << "Can not be placed there." << endl;
      continue;
    }
    omok.IsOmok(&winner);
  }

  // print ground and winner;
  cout << omok;
  if(winner == BLACK)
    cout << "Winner : Black Player" << endl;
  else
    cout << "Winner : White Player" << endl;

  return 0;
}
