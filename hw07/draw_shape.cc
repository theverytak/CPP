// draw_shape.cc
// 2016. 7 .30

#include "draw_shape.h"

// start of Canvas Class
// constructor and destructor
Canvas::Canvas(size_t row, size_t col) {
  for(int i = 0; i < row; i++) {
    string str;
    for(int j = 0; j < col; j++)
      str += ".";
    pictures_.push_back(str);
  }
}
Canvas::~Canvas() { pictures_.clear(); }

void Canvas::Resize(size_t w, size_t h) {
  pictures_.resize(h);
  for(int i = 0; i < h; i++)
    pictures_[i].resize(w);
}

bool Canvas::Draw(int x, int y, char brush) {
  // if location of (x, y) is out of the pictures_
  if(x < 0 || y < 0 || x >= pictures_.front().size() || y >= pictures_.size())
    return false;

  pictures_[y][x] = brush;

  return true;
}

void Canvas::Clear() {
  for(int i = 0; i < pictures_.size(); i++)
    for(int j = 0; j < pictures_[i].size(); j++)
      pictures_[i][j] = '.';
}
// end of Canvas class


// start of Rectangle class
void Rectangle::Draw(Canvas* cv) const {
  for(int i = y(); i < y() + h(); i++)
    for(int j = x(); j < x() + w(); j++)
      cv->Draw(j, i, brush());
}
// end of Rectangle class


// start of UpTriangle class
void UpTriangle::Draw(Canvas* cv) const {
  for(int i = y(); i < y() + h(); i++)
    for(int j = x() - (i - y()); j <= x() + (i - y()); j++)
      cv->Draw(j , i, brush());
}
// end of UpTriangle class


// start of DownTriangle class
void DownTriangle::Draw(Canvas* cv) const {
  for(int i = y() - h() + 1; i <= y(); i++)
    for(int j = x() - (y() - i); j <= x() + (y() - i); j++)
      cv->Draw(j , i, brush());
}
// end of DownTriangle class


// start of Diamond class
void Diamond::Draw(Canvas* cv) const {
  for(int i = y(); i < y() + h(); i++)
    for(int j = x() - (i - y()); j <= x() + (i - y()); j++)
      cv->Draw(j , i, brush());

  for(int i = y() + h(); i <= y() + h() * 2; i++)
    for(int j = x() - (2 * y() - i - 1); j <= x() + (2 * y() - i - 1); j++)
      cv->Draw(j, i, brush());
}
// end of Diamond class


ostream& operator<<(ostream& os, const Canvas& c) {
  os << " ";
  for(int i = 0; i < c.pictures_.front().size(); i++)
    os << i % 10;
  os << endl;

  for(int i = 0; i < c.pictures_.size(); i++)
    os << i << c.pictures_[i] << endl;

  return os;
}

istream& operator>>(istream& is, Rectangle& r) {
  is >> r.x_ >> r.y_ >> r.width_ >> r.height_ >> r.brush_;

  return is;
}

istream& operator>>(istream& is, UpTriangle& t) {
  is >> t.x_ >> t.y_ >> t.height_ >> t.brush_;

  return is;
}

istream& operator>>(istream& is, DownTriangle& d) {
  is >> d.x_ >> d.y_ >> d.height_ >> d.brush_;

  return is;
}

istream& operator>>(istream& is, Diamond& dm) {
  is >> dm.x_ >> dm.y_ >> dm.height_ >> dm.brush_;

  return is;
}
