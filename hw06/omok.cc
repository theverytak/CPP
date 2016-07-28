// omok.cc
// 2016. 7. 28

#include "omok.h"

int Omok::Put(int x, int y) {
  if(x < 0 || y < 0 || x >= GROUND_SIZE || y >= GROUND_SIZE ||
     ground_[y][x] != '.')
    return NOBODY;

  if(Turn() == BLACK) {
    ground_[y][x] = 'O';
    turn_ = WHITE;
    return BLACK;
  }
  else if(Turn() == WHITE) {
    ground_[y][x] = 'X';
    turn_ = BLACK;
    return WHITE;
  }
}

void Omok::IsOmok(int* winner) const {
  int turn = (Turn() == BLACK) ? WHITE : BLACK;
  for(int i = 0; i < GROUND_SIZE; i++) {
    for(int j = 0; j < GROUND_SIZE; j++) {
      if(CheckHorizon(j, i) == 5 || CheckVertical(j, i) == 5 ||
         CheckDiagonalDown(j, i) == 5 || CheckDiagonalUp(j, i) == 5) {
        *winner = turn;
        return ;
      }
    }
  }
}

int Omok::CheckHorizon(int x, int y) const {
  int count = 0;  // count will be the return val;

  // stone is the one this func currenctly checks;
  char stone = (Turn() == BLACK) ? 'X' : 'O';

  // if (x, y) != stone
  if(ground_[y][x] == stone)
    return 0;

  // check <- direction;
  for(int i = x; i >= 0; i--) {
    if(ground_[y][i] == stone)
      count++;
    else
      break;
  }

  // check -> direction
  for(int i = x + 1; i < GROUND_SIZE; i++) {
    if(ground_[y][i] == stone)
      count++;
    else
      break;
  }

  return count;
}
int Omok::CheckVertical(int x, int y) const {
  int count = 0;  // count will be the return val;

  // stone is the one this func currenctly checks;
  char stone = (Turn() == BLACK) ? 'X' : 'O';

  // if (x, y) != stone
  if(ground_[y][x] == stone)
    return 0;

  // check vertically-up direction;
  for(int i = y; i >= 0; i--) {
    if(ground_[i][x] == stone)
      count++;
    else
      break;
  }

  // check vertically-down direction
  for(int i = y + 1; i < GROUND_SIZE; i++) {
    if(ground_[i][x] == stone)
      count++;
    else
      break;
  }

  return count;

}
int Omok::CheckDiagonalDown(int x, int y) const {
  int count = 0;  // count will be the return val;

  // stone is the one this func currenctly checks;
  char stone = (Turn() == BLACK) ? 'X' : 'O';

  // if (x, y) != stone
  if(ground_[y][x] == stone)
    return 0;

  // check 11 o' clock direction;
  for(int i = 0; x - i >= 0 && y - i >= 0; i++) {
    if(ground_[y - i][x - i] == stone)
      count++;
    else
      break;
  }

  // check 5 o' clock direction;
  for(int i = 1; x + i < GROUND_SIZE && y + i < GROUND_SIZE; i++) {
    if(ground_[y + i][x + i] == stone)
      count++;
    else
      break;
  }

  return count;
}


int Omok::CheckDiagonalUp(int x, int y) const {
  int count = 0;  // count will be the return val;

  // stone is the one this func currenctly checks;
  char stone = (Turn() == BLACK) ? 'X' : 'O';

  // if (x, y) != stone
  if(ground_[y][x] == stone)
    return 0;

  // check 7 o' clock direction;
  for(int i = 0; x - i >= 0 && y + i < GROUND_SIZE; i++) {
    if(ground_[y + i][x - i] == stone)
      count++;
    else
      break;
  }
  // check 2 o' clock direction;
  for(int i = 1; x + i < GROUND_SIZE && y - i >= 0; i++) {
    if(ground_[y - i][x + i] == stone)
      count++;
    else
      break;
  }

  return count;
}

ostream& operator<<(ostream& os, const Omok& omok) {
  for(int i = 0; i < GROUND_SIZE; i++) {
    for(int j = 0; j < GROUND_SIZE; j++) {
      os << omok.ground_[i][j] << " ";
    }
    os << endl;
  }

  return os;
}
