// draw_shape.cc
// 2016. 7. 21

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
  if(!IsValidInput(s))
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
      int h = 0;    // for make a triangle shape;
      for(int i = (it->y) - (it->height) + 1; i <= (it->y); i++) {
        for(int j = (it->x) - (it->width / 2) + h;
            j <= (it->x) + (it->width / 2) - h; j++)
          pictures_[i][j] = it->brush;
        h++;
      }
    }
    else if(it->type == TRIANGLE_UP) {  // if it's a triangle_up;
      int h = it->height - 1;    // for make a triangle shape;
      for(int i = (it->y); i <= (it->y) + (it->height) - 1; i++) {
        for(int j = (it->x) - (it->width / 2) + h;
            j <= (it->x) + (it->width / 2) - h; j++)
          pictures_[i][j] = it->brush;
        h--;
      }
    }
  }

  // printing;
  os << " ";
  for(int i = 0; i < col_; i++)
    os << i % 10;
  os << endl;
  for(int i = 0; i < pictures_.size(); i++)
    os << i % 10 << pictures_[i] << endl;
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


bool Canvas::IsValidInput(const Shape& s) {
  if(s.type == RECTANGLE) {
    if(s.width % 2 == 0 || s.height % 2 == 0)
      return false;
  }
  else {
    if(s.width <= 0 || s.height <= 0)
      return false;
  }

  return true;
}

bool Canvas::IsInsideCanvas(const Shape &s) {
  if(s.type == RECTANGLE) {
    // checking x coordinate range;
    if((s.x) - (s.width / 2) < 0 || (s.x) + (s.width / 2) >= pictures_[0].size())
      return false;
    // checking y coordinate range;
    if((s.y) - (s.height / 2) < 0 || (s.y) + (s.height / 2) >= pictures_.size())
      return false;
  }
  else if(s.type == TRIANGLE_DOWN) {
    // checking x coordinate range;
    if((s.x) - (s.width / 2) < 0 || (s.x) + (s.width / 2) >= pictures_[0].size())
      return false;
    // checking y coordinate range;
    if((s.y) - (s.height) + 1 < 0 || (s.y) >= pictures_.size())
      return false;
  }
  else if(s.type == TRIANGLE_UP) {
    // checking x coordinate range;
    if((s.x) - (s.width / 2) < 0 || (s.x) + (s.width / 2) >= pictures_[0].size())
      return false;
    // checking y coordinate range;
    if((s.y) < 0 || (s.y) + (s.height) - 1 >= pictures_.size())
      return false;
  }

  return true;
}
