// sort_int.cc
// 2016. 7. 12

#include <iostream>

void Swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

void SortInt(int *ary, const int num) {
  for(int i = 0; i < num; i++) {
    for(int j = 0; j < num - 1; j++) {
      if(ary[j] > ary[j + 1]) {
        Swap(&ary[j], &ary[j + 1]);
      }
    }
  }
}

int main() {

  int num;
  int *ary;
  std::cin >> num;

  if(num <= 0) {
    return 0;
  }

  ary = new int[num];

  for(int i = 0; i < num; i++) {
    std::cin >> ary[i];
  }

  SortInt(ary, num);

  for(int i = 0; i < num; i++) {
    std::cout << ary[i] << " ";
  }

  delete[] ary;

  return 0;
}
