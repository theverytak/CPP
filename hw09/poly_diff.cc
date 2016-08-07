// poly_diff.cc
// 2016. 8. 7

#include "poly_diff.h"

void Polynomial::addFunction(string expression) {
  int coef, exponent;
  int coefStart = 0, coefEnd = 0;
  int exStart = 0, exEnd = 0;
  string::size_type sz;

  for(int i = 0; i < expression.length(); i++) {
    if(expression[i] == 'x') {
      coefEnd = i;
      if(coefStart == coefEnd)
        coef = 1;
      else {
        coef = stoi(string(expression.begin() + coefStart,
                    expression.begin() + coefEnd), &sz);
        if(expression[i + 1] == '^') {
          exStart = i + 2;
          for(int j = exStart; j < expression.length(); j++) {
            if(expression[j] == '+' || expression[j] == '\0') {
              exEnd = j;
              exponent = stoi(string(expression.begin() + exStart,
                              expression.begin() + exEnd), &sz);
              coefStart = exEnd + 1;
              break;
            }
          }
        }
        else {
          exponent = 1;
          coefStart = i + 2;
        }
        f_.insert(pair<int, int>(exponent, coef));
      }
    }
  }
}

void Polynomial::makeFPrime() {
  int coef, exponent;
  for(auto it = f_.begin(); it != f_.end(); it++) {
    exponent = it->first - 1;
    coef = it->first * it->second;
    fPrime_.insert(pair<int, int>(exponent, coef));
  }
}

int Polynomial::fPrimeResult(int x) {
  int sum = 0;

  for(auto it = fPrime_.begin(); it != fPrime_.end(); it++) {
    sum += it->second * static_cast<int>(pow(x, it->first));
  }

  return sum;
}
