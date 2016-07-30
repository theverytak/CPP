// sorted_array.h
// 2016. 7. 21

#ifndef _SORTED_ARRAY_H_
#define _SORTED_ARRAY_H_
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // for std::sort;

using namespace std;

class SortedArray {
 public:
  SortedArray() {}
  ~SortedArray() {}

  void AddNumber(int num);

  vector<int> GetSortedAscending() const;
  vector<int> GetSortedDescending() const;
  int GetMax() const;
  int GetMin() const;

 private:
  vector<int> numbers_;
};

void ParseNAdd(string str, SortedArray& sa);
void PrintVector(const vector<int>& v);

#endif  // _SORTED_ARRAY_H_
