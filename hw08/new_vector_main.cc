// new_vector_main.cc
// 2016. 8. 7

#include "new_vector.h"

int main() {
  NewVector nv = NewVector();
  while(true) {
      string type;
      cin >> type;

      if(type == "i") {
          int value;
          cin >> value;
          nv.add(value); // replace to nv.add<int>(value) when error occurs
      } else if(type == "d") {
          double value;
          cin >> value;
          nv.add(value); // replace to nv.add<double>(value) when error occurs
      } else if(type == "c") {
          char value;
          cin >> value;
          nv.add(value); // replace to nv.add<char>(value) when error occurs
      }
      else if(type == "print") cout << nv;
      else if(type == "q") break;
  }
  
  return 0;
}
