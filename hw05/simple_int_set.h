// simple_int_set.h
// 2016. 7. 21

#ifndef _SIMPLE_INT_SET_H_
#define _SIMPLE_INT_SET_H_
#include <set>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class SimpleIntSet
{
  private:
    set<int> intSet;

  public:
    set<int> SetIntersection(const set<int>& set0, const set<int>& set1);
    set<int> SetUnion(const set<int>& set0, const set<int>& set1);
    set<int> SetDifference(const set<int>& set0, const set<int>& set1);
    void PrintSet() const;
    void AddNumber(const int num);
    set<int> IntSet() const;
};

bool isValidInput(const string& str);   // just check first char;
void parseNMake(const string& str, SimpleIntSet& set0,
                SimpleIntSet& set1, char& operand);

#endif  //_SIMPLE_INT_SET_H_
