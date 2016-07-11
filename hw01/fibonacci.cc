// fibonacci.cc
// 2016. 7. 11

#include <iostream>

int fibonacci(int num, int onoff) {
  int result;

  // if onoff == 1, print, else no print;
  if(onoff) {
    if(num == 1)
      result = 1;
    else if(num == 2) {
      fibonacci(1, 1);
      result = 1;
    }

    else
      result = fibonacci(num - 1, 1) + fibonacci(num - 2, 0);

    std::cout << result << " ";
  }
  else if(!onoff) {
    if(num == 1 || num == 2)
      result = 1;
    else
      result = fibonacci(num - 1, 0) + fibonacci(num - 2, 0);
  }
  return result;
}

int main() {
  int num;  // variable for input;
  std::cin >> num;

  // if num is negative or 0, close the program;
  if(num <= 0) return 0;

  fibonacci(num, 1);

  return 0;
}
