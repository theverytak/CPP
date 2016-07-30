// draw_shape.h
// 2016. 7. 30

#ifndef _DRAW_SHAPE_H_
#define _DRAW_SHAPE_H_
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Canvas {
  public:
    Canvas(size_t row, size_t col);
    ~Canvas();

    // change the size of pictures_ to w by h. conserve already drawed pics.
    void Resize(size_t w, size_t h);

    // draw brush at (x, y). ignore (x, y) out of the range;
    bool Draw(int x, int y, char brush);

    // erase canvas and re-initiallize pictures_ with '.'
    void Clear();

  private:
    vector<string> pictures_;
    friend ostream& operator<<(ostream& os, const Canvas& c);
};

class Shape {
  public:
    virtual ~Shape() {}
    virtual void Draw(Canvas* cv) const = 0;
    int x() const { return x_; }
    int y() const { return y_; }
    int w() const { return width_; }
    int h() const { return height_; }
    char brush() const { return brush_; }
    string type() const { return type_; }
  protected:
  // common property of shapes.
  // top left coord for Rectangle;
  // vertex for triangle;
  // top point for diamond
    int x_, y_, height_, width_;
    string type_;
    char brush_;
};

class Rectangle : public Shape {
  public:
    Rectangle() : Shape() { type_ = "rect"; }
    virtual ~Rectangle() {}
    virtual void Draw(Canvas* cv) const;

  private:
    friend istream& operator>>(istream& is, Rectangle& r);

};

class UpTriangle : public Shape {
  public:
    UpTriangle() : Shape() { type_ = "tri_up"; }
    virtual ~UpTriangle() {}
    virtual void Draw(Canvas* cv) const;

  private:
    friend istream& operator>>(istream& is, UpTriangle& r);
};

class DownTriangle : public Shape {
  public:
    DownTriangle() : Shape() { type_ = "tri_down"; }
    virtual ~DownTriangle() {}
    virtual void Draw(Canvas* cv) const;

  private:
    friend istream& operator>>(istream& is, DownTriangle& r);
};

class Diamond : public Shape {
public:
  Diamond() : Shape() { type_ = "diamond"; }
  virtual ~Diamond() {}
  virtual void Draw(Canvas* cv) const;

private:
  friend istream& operator>>(istream& is, Diamond& r);
};


ostream& operator<<(ostream& os, const Canvas& c);
istream& operator>>(istream& is, Rectangle& r);
istream& operator>>(istream& is, UpTriangle& t);
istream& operator>>(istream& is, DownTriangle& d);
istream& operator>>(istream& is, Diamond& dm);

#endif  // _DRAW_SHAPE_H_
