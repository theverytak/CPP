// poly_diff_main.cc
// 2016. 8. 7

#include "poly_diff.h"

int main() {
  string expression;
  while(true) {
    cin >> expression;

    if(expression == "quit")
      break;

    else {
      Polynomial p;
      p.addFunction(expression);
      p.makeFPrime();
      int x;
      cin >> x;
      cout << p.fPrimeResult(x) << endl;
    }
  }

  return 0;
}
