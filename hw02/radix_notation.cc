// radix_notation.cc
// 2016. 7. 13

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void StringReverse(string *str) {
  string result;
  //std::cout << str << std::endl;
  for(string::reverse_iterator rit=str->rbegin(); rit!=str->rend(); ++rit) {
    //std::cout << *it << " ";
    result += *rit;
  }
  *str = result;
}

// Implement this function.
string RadixNotation(unsigned int number, unsigned int radix) {
  string result;
  int leftover;
  char leftover_to_char;
  while(number != 0) {
    leftover = number % radix;
    number /= radix;
    if(leftover < 10) {
      leftover_to_char = leftover + '0';
    }
    else {
      leftover_to_char = leftover + 'a' - 10;
    }
    result += leftover_to_char;
  }
  StringReverse(&result);
  return result;
}


int main(int argc, char** argv) {
  if (argc < 2) return -1;
  unsigned int radix;
  sscanf(argv[1], "%u", &radix);
  if (radix < 2 || radix > 36) return -1;
  for (int i = 2; i < argc; ++i) {
    unsigned int number;
    sscanf(argv[i], "%u", &number);
    cout << RadixNotation(number, radix) << endl;
  }
  return 0;
}
