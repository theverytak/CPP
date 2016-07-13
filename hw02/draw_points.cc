// draw_points.cc
// 2016. 7. 13

#include <iostream>

using namespace std;

struct Point {
  int x;
  int y;
};

int FindMaxX(Point *p, int num_of_points) {
  int max = 0;
  for(int i = 0; i < num_of_points; i++) {
    if(p[i].x > max) {
      max = p[i].x;
    }
  }

  // the reason why return max + 1? max should be the length of row all col. not the last index of row or col;
  return max + 1;
}

int FindMaxY(Point *p, int num_of_points) {
  int max = 0;
  for(int i = 0; i < num_of_points; i++) {
    if(p[i].y > max) {
      max = p[i].y;
    }
  }
  return max + 1;
}

void DrawPoints(Point *p, int num_of_points) {
  int max_x = FindMaxX(p, num_of_points);
  int max_y = FindMaxY(p, num_of_points);

  // make a char array;
  char *picture = new char[max_y * max_x];

  // initiallize array with '.';
  for(int i = 0; i < max_y; i++) {
    for(int j = 0; j < max_x; j++) {
      picture[i * max_x + j] = '.';
    }
  }

  // draw the points with '*';
  for(int i = 0; i < num_of_points; i++) {
    picture[p[i].y * max_x + p[i].x] = '*';
  }

  // print it;
  for(int i = 0; i < max_y; i++) {
    for(int j = 0; j < max_x; j++) {
      cout << picture[i * max_x + j];
    }
    cout << endl;
  }

  delete[] picture;
}


int main() {
  //a pointer for Struct Point;
  Point p[10];
  int num_of_points = 0;
  int input_x, input_y;

  while(1) {
  // get x, y and if one of them is negative, break;
  cin >> input_x >> input_y;
  if(input_x < 0 || input_y < 0) {
    break;
  }

  // make a new Point;
  p[num_of_points].x = input_x;
  p[num_of_points].y = input_y;
  num_of_points++;

  // draw the point;
  DrawPoints(p, num_of_points);
  }
  return 0;
}
