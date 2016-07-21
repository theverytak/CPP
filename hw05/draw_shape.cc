// draw_shape.cc
// 2017. 7. 21

#include "draw_shape.h"

// constructor and destructor. constructor initialize the pictures_ with dots;
Canvas::Canvas(size_t row, size_t col) {
  row_ = row;
  col_ = col;
  pictures_.resize(row);
  for(int i = 0; i < row; i++)
    for(int j = 0; j < col; j++)
      pictures_[i] += '.';
}
Canvas::~Canvas() {}

// Return the index of the shape.
int Canvas::AddShape(const Shape &s) {
  // if theres error with input, return error enum;
  if(!IsValidInput(s.width, s.height))
    return ERROR_INVALID_INPUT;
  if(!IsInsideCanvas(s))
    return ERROR_OUT_OF_CANVAS;

  shapes_.push_back(s);
  return shapes_.size() - 1;
}

// ignore if index is invalid;
void Canvas::DeleteShape(int index) {
  if(shapes_.size() <= index)
    return ;

  shapes_.erase(shapes_.begin() + index);
}

// start with initializing pictures_ to '.' and draw;
void Canvas::Draw(ostream& os) {
  // initializing pictures_ with '.';
  for(int i = 0; i < pictures_.size(); i++)
    for(int j = 0; j < pictures_[0].size(); j++)
      pictures_[i][j] = '.';

  // drawing;
  for(auto it = shapes_.cbegin(); it != shapes_.cend(); it++) {
    if(it->type == RECTANGLE) { // if it's a rectangle;
      for(int i = (it->y) - (it->height / 2); i <= (it->y) + (it->height / 2); i++)
        for(int j = (it->x) - (it->width / 2); j <= (it->x) + (it->width / 2); j++)
          pictures_[i][j] = it->brush;
    }
    else if(it->type == TRIANGLE_DOWN) {  // if it's a triangle_down;
      for(int i = (it->y) - (it->height) + 1; i <= (it->y); i++)
        for(int j = (it->x) - (it->width / 2); j <= (it->x) + (it->width / 2); j++)
          pictures_[i][j] = it->brush;
    }
    else if(it->type == TRIANGLE_UP) {  // if it's a triangle_up;
      for(int i = (it->y); i <= (it->y) + (it->height) - 1; i++)
        for(int j = (it->x) - (it->width / 2); j <= (it->x) + (it->width / 2); j++)
          pictures_[i][j] = it->brush;
    }
  }

  // printing;
  for(auto it = pictures_.cbegin(); it != pictures_.cend(); it++)
    os << *it << endl;
}

void Canvas::Dump(ostream& os) {
  for(int i = 0; i < shapes_.size(); i++) {
    if(shapes_[i].type == RECTANGLE) {
      os << i << " rect " << shapes_[i].x << " " << shapes_[i].y << " "
         << shapes_[i].width << " " << shapes_[i].height << " "
         << shapes_[i].brush << endl;
    }
    else if(shapes_[i].type == TRIANGLE_DOWN) {
      os << i << " tri_down " << shapes_[i].x << " " << shapes_[i].y << " "
         << shapes_[i].height << " " << shapes_[i].brush << endl;
    }
    else if(shapes_[i].type == TRIANGLE_UP) {
      os << i << " tri_up " << shapes_[i].x << " " << shapes_[i].y << " "
         << shapes_[i].height << " " << shapes_[i].brush << endl;
    }
  }
}


bool Canvas::IsValidInput(const int& width, const int& height) {
  return true;
}

bool Canvas::IsInsideCanvas(const Shape &s) {
  return true;
}
