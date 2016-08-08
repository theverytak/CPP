// poly_diff.cc
// 2016. 8. 7

#include "poly_diff.h"

void Polynomial::addFunction(string expression) {
  int termStart = 0, termEnd = 0;
  int coef, exponent;


  for(int i = 0; i <= expression.length(); i++) {
    if(expression[i] == '+' || expression[i] == '\0') {
      termEnd = i;
      coef = findCoef(expression, termStart, termEnd);
      exponent = findExp(expression, termStart, termEnd);
      //cout << "coef n exp : " << coef << " " << exponent << endl;
      termStart = i + 1;

      if(exponent != 0)
        f_.insert(pair<int, int>(exponent, coef));
    }
  }
}

void Polynomial::makeFPrime() {
  int coef, exponent;
  for(auto it = f_.begin(); it != f_.end(); it++) {
    exponent = it->first - 1;
    coef = it->first * it->second;
  //  cout << "coef' n exp' : " << coef << " " << exponent << endl;
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

int findCoef(string expression, int termStart, int termEnd) {
  string singleTerm = string(expression.begin() + termStart,
                             expression.begin() + termEnd);

  // if it's a constant term;
  if(singleTerm.find('x') == string::npos)
    return -1;

  for(int i = 0; i < singleTerm.length(); i++) {
    if(singleTerm[i] == 'x' && i == 0)
      return 1;

    else if(singleTerm[i] == 'x' && singleTerm[i - 1] == '-')
      return -1;

    else if(singleTerm[i] == 'x' && i != 0) {
      string::size_type sz;
      return stoi(string(singleTerm.begin(), singleTerm.begin() + i), &sz);
    }
  }
}

int findExp(string expression, int termStart, int termEnd) {
  string singleTerm = string(expression.begin() + termStart,
                             expression.begin() + termEnd);

  if(singleTerm.find('x') == string::npos)
    return -1;

  if(singleTerm.find('^') == string::npos)
    return 1;

  for(int i = 0; i < singleTerm.length(); i++) {
    if(singleTerm[i] == '^') {
      string::size_type sz;
      return stoi(string(singleTerm.begin() + i + 1, singleTerm.end()), &sz);
    }
  }
}
