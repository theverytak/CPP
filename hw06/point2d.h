// point2d.h
// 2017. 7. 27

#ifndef _POINT2D_H_
#define _POINT2D_H_
#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Point {
  int x_, y_;  // 멤버 변수.

  Point();
  Point(const Point& p);
  explicit Point(int c) {
    x_ = c;
    y_ = c;
  }
  Point(int x, int y);

  Point operator-() const;  // 전위 - 연산자
};

Point operator+(const Point& lhs, const Point& rhs);
Point operator-(const Point& lhs, const Point& rhs);
Point operator*(const Point& lhs, const Point& rhs);
Point Calc(const Point& lhs, const Point& rhs, const char operand);

#endif  // _POINT2D_H_
