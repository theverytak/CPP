// point2d.cc
// 2017. 7. 27

#include "point2d.h"

Point::Point() {}
Point::Point(const Point& p) {
  x_ = p.x_;
  y_ = p.y_;
}
Point::Point(int x, int y) {
  x_ = x;
  y_ = y;
}
Point Point::operator-() const {
  return Point(-1 * x_, -1 * y_);
}

Point operator+(const Point& lhs, const Point& rhs) {
  return Point(lhs.x_ + rhs.x_, lhs.y_ + rhs.y_);
}

Point operator-(const Point& lhs, const Point& rhs) {
  return Point(lhs.x_ - rhs.x_, lhs.y_ - rhs.y_);
}

Point operator*(const Point& lhs, const Point& rhs) {
  return Point(lhs.x_ * rhs.x_, lhs.y_ * rhs.y_);
}

Point Calc(const Point& lhs, const Point& rhs, const char operand){
  if(operand == '+') {
    return lhs + rhs;
  }
  else if(operand == '-') {
    return lhs - rhs;
  }
  else if(operand == '*') {
    return lhs * rhs;
  }
}
