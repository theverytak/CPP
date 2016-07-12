// magic_square.cc
// 2016. 7. 12

#include <iostream>

void MagicSquare(int *square, const int num) {
  // first (row, col) == (0, mid), target for number ready to put;
  int row = 0, col = num / 2;

  square[row * num + col] = 1;

  for(int target = 2; target != num * num + 1; target++) {
    row -= 1;
    col += 1;

    if(row < 0 && col >= 0 && col < num) {
      row = num - 1;
      square[row * num + col] = target;
    }
    else if(row >= 0 && row < num && col >= num) {
      col = 0;
      square[row * num + col] = target;
    }
    else if((row < 0 && col >= num) || square[row * num + col] != 0) {
      row += 2;
      col -= 1;
      square[row * num + col] = target;
    }
    else {
      square[row * num + col] = target;
    }
  }
}

int main() {
  int num;
  int *square;
  std::cin >> num;

  // if input num is negative or even, close the program;
  if(num < 0 || num % 2 == 0)
    return 0;

  // square array dynamically allocated, and initiallize all members to 0;
  square = new int[num * num];
  for(int i = 0; i < num; i++)
    for(int j = 0; j < num; j++)
      square[i * num + j] = 0;

  // MagicSquare function put all good numbers to the square array;
  MagicSquare(square, num);

  // print it;
  for(int i = 0; i < num; i++) {
    for(int j = 0; j < num; j++)
      std::cout << square[i * num + j] << " ";
    std::cout <<  std::endl;
  }

  // free the memory;
  delete[] square;

  return 0;
}
