// parse_radix.h
// 2016. 7. 27

#ifndef _PARSE_RADIX_H_
#define _PARSE_RADIX_H_
#include <iostream>
#include <string>
#include <math.h>  // for pow;

using namespace std;

bool compare(int lhs, int rhs, string operand);
int calculate(int lhs, int rhs, string operand);
void stringReverse(string *str);
string convertRadix(int number, int radix);
int parseRadix(const string& numNRadix);


#endif  // _PARSE_RADIX_H_
