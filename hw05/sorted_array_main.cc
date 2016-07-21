// sorted_array_main.cc
// 2017. 7. 21

#include "sorted_array.h"

int main() {
  string numberStr;
  SortedArray sa;

  getline(cin, numberStr);
  // parsing numberStr and add the numbers to sa;
  ParseNAdd(numberStr, sa);

  while(true) {
    // get command;
    string command;
    getline(cin, command);

    // do according to the command;
    if(isdigit(command[0])) {
      // if its a number array, not a real command;
      ParseNAdd(command, sa);
    }
    else if(command == "ascend") {
      // ascend;
      vector<int> ascendingArray = sa.GetSortedAscending();
      // print;
      PrintVector(ascendingArray);
    }
    else if(command == "descend") {
      // descend;
      vector<int> descendingArray = sa.GetSortedDescending();
      // print;
      PrintVector(descendingArray);
    }
    else if(command == "max") {
      // max;
      cout << sa.GetMax() << endl;
    }
    else if(command == "min") {
      // min;
      cout << sa.GetMin() << endl;
    }
    else {
      // quit;
      break;
    }
  }

  return 0;
}
