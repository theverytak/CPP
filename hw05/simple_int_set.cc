// simple_int_set.cc
// 2017. 7. 21

#include "simple_int_set.h"


bool isValidInput(const string& str) {
  return (str[0] == '{');
}

void parseNMake(const string& str, SimpleIntSet& set0,
                SimpleIntSet& set1, char& operand) {
  string str0, str1;
  // find operand and make two string contains set;
  // also, to reuse the ParseNAdd function, used in hw05/sorted_array.cc,
  // remove the '{', ' ', '}' while making str0 and str1;
  // ex) "{ 1 2 3 } + { 2 3 }" -> "1 2 3", "2 3";
  for(auto it = str.cbegin(); it != str.cend(); it++) {
    if(*it == '+' || (*it == '-' && *(it + 1) == ' ') || *it == '*') {
      operand = *it;
      str0 = string(str.cbegin() + 2, it - 3);
      str1 = string(it + 4, str.cend() - 2);
    }
  }
  // make set0;
  auto itS = str0.cbegin(), itE = str0.cbegin();
  while(true) {    // condition sentence need to be fixed;
    if(*itE == ' ' || itE == str0.cend()) {
      string::size_type sz;   // alias of size_t
      int num = stoi(string(itS, itE), &sz);
      set0.AddNumber(num);
      if(itE == str0.cend())
        break;
      itE++;
      itS = itE;
    }
    else {
      itE++;
    }
  }
  // make set1;
  itS = str1.cbegin(), itE = str1.cbegin();
  while(true) {    // condition sentence need to be fixed;
    if(*itE == ' ' || itE == str1.cend()) {
      string::size_type sz;   // alias of size_t
      int num = stoi(string(itS, itE), &sz);
      set1.AddNumber(num);
      if(itE == str1.cend())
        break;
      itE++;
      itS = itE;
    }
    else {
      itE++;
    }
  }
}

set<int> SimpleIntSet::IntSet() const {
  return intSet;
}

void SimpleIntSet::PrintSet() const {
  cout << "{ ";
  for(auto it = intSet.cbegin(); it != intSet.cend(); it++) {
      cout << *it << " ";
  }
  cout << "}" << endl;
}

// just insert a number. if it alreay exists, doesn't matter cuz
// stl set will ignore it;
void SimpleIntSet::AddNumber(const int num) {
  intSet.insert(num);
}

set<int> SimpleIntSet::SetIntersection(const set<int>& set0,
                                       const set<int>& set1) {
  for(auto it0 = set0.cbegin(); it0 != set0.cend(); it0++) {
    for(auto it1 = set1.cbegin(); it1 != set1.cend(); it1++) {
      if(*it0 == *it1)
        AddNumber(*it0);
    }
  }

  return IntSet();
}

set<int> SimpleIntSet::SetUnion(const set<int>& set0,
                                const set<int>& set1) {
  for(auto it = set0.cbegin(); it != set0.cend(); it++)
    AddNumber(*it);
  for(auto it = set1.cbegin(); it != set1.cend(); it++)
    AddNumber(*it);

  return IntSet();
}

set<int> SimpleIntSet::SetDifference(const set<int>& set0,
                                     const set<int>& set1) {
  for(auto it0 = set0.cbegin(); it0 != set0.cend(); it0++) {
    bool isDifference = true;
    for(auto it1 = set1.cbegin(); it1 != set1.cend(); it1++) {
      if(*it0 == *it1) {
        isDifference = false;
        break;
      }
    }
    if(isDifference)
      AddNumber(*it0);
  }

  return IntSet();
}
