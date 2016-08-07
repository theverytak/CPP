// poly_diff.h
// 2016. 8. 7

#ifndef _POLY_DIFF_H_
#define _POLY_DIFF_H_

#include <string>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

class Polynomial {
  public:
    Polynomial() {}
    void addFunction(string expression);
    void makeFPrime();
    int fPrimeResult(int x);

  private:
    map<int, int> f_;   // don't save constant term;
    map<int, int> fPrime_;
};

#endif  // _POLY_DIFF_H_
