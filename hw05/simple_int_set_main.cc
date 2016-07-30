// simple_int_set_main.cc
// 2016. 7. 21

#include "simple_int_set.h"


int main() {
  while(true) {
    string setInput;
    SimpleIntSet set0, set1;
    char operand;

    // if input set is not a real set, break and close the program;
    getline(cin, setInput);
    if(!isValidInput(setInput))
      break;

    // make set0 and set1, also save the operand(+, -, *);
    parseNMake(setInput, set0, set1, operand);
    if(operand == '+') {
      // union;
      SimpleIntSet res;
      res.SetUnion(set0.IntSet(), set1.IntSet());
      res.PrintSet();
    }
    else if(operand == '-') {
      // difference;
      SimpleIntSet res;
      res.SetDifference(set0.IntSet(), set1.IntSet());
      res.PrintSet();
    }
    else if(operand == '*') {
      // intersect;
      SimpleIntSet res;
      res.SetIntersection(set0.IntSet(), set1.IntSet());
      res.PrintSet();
    }
    else {
      // abnormal input;
      break;
    }
  }
  return 0;
}
