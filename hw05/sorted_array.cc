// sorted_array.cc
// 2016. 7. 21

#include "sorted_array.h"

void ParseNAdd(string str, SortedArray& sa) {
  auto itS = str.begin(), itE = str.begin();
  while(true) {    // condition sentence need to be fixed;
    if(*itE == ' ' || itE == str.end()) {
      string::size_type sz;   // alias of size_t
      int num = stoi(string(itS, itE), &sz);
      sa.AddNumber(num);
      if(itE == str.end())
        break;
      itE++;
      itS = itE;
    }
    else {
      itE++;
    }
  }
}

void PrintVector(const vector<int>& v) {
  for(auto it = v.cbegin(); it != v.cend(); it++)
    cout << *it << " ";
  cout << endl;
}

// add a number to the vector and sort it;
void SortedArray::AddNumber(int num) {
  numbers_.push_back(num);
  sort(numbers_.begin(), numbers_.end());
}

vector<int> SortedArray::GetSortedAscending() const {
  vector<int> result = numbers_;
  return result;
}

vector<int> SortedArray::GetSortedDescending() const {
  vector<int> result;
  for(auto rit = numbers_.rbegin(); rit != numbers_.rend(); rit++)
    result.push_back(*rit);
  return result;
}

int SortedArray::GetMax() const {
  return numbers_.back();
}

int SortedArray::GetMin() const {
  return numbers_.front();
}
