// draw_shape_main.cc
// 2016. 7. 21

#include "draw_shape.h"

int main() {
  // make a Canvas and draw it; it should be all dots('.');
  int row, col;
  cin >> row >> col;
  Canvas cv(row, col);
  cv.Draw(cout);

  while(true) {
    // get a command;
    string command;
    cin >> command;

    if(command == "add") {
      // get a shape -> examine being valid, inside -> add;
      string type;
      cin >> type;
      if(type == "rect") {
        // make a rectangle;
        int x, y, width, height;
        char brush;
        cin >> x >> y >> width >> height >> brush;
        Shape s;
        s.x = x; s.y = y; s.width = width; s.height = height;
        s.brush = brush; s.type = RECTANGLE;

        // add to canvas;
        int addResult = cv.AddShape(s);
        if(addResult == ERROR_OUT_OF_CANVAS)
          cout << "ERROR OUT OF CANVAS" << endl;
        else if(addResult == ERROR_INVALID_INPUT)
          cout << "ERROR INVALID INPUT" << endl;
      }
      else if(type == "tri_down") {
        // make a triangle_down
        int x, y, width, height;
        char brush;
        cin >> x >> y >> height >> brush;   // don't need width;
        Shape s;
        s.x = x; s.y = y; s.width = height * 2 - 1; s.height = height;
        s.brush = brush; s.type = TRIANGLE_DOWN;

        // add to canvas;
        int addResult = cv.AddShape(s);
        if(addResult == ERROR_OUT_OF_CANVAS)
          cout << "ERROR OUT OF CANVAS" << endl;
      }
      else if(type == "tri_up") {
        // make a triangle_up
        int x, y, width, height;
        char brush;
        cin >> x >> y >> height >> brush;   // don't need width;
        Shape s;
        s.x = x; s.y = y; s.width = height * 2 - 1; s.height = height;
        s.brush = brush; s.type = TRIANGLE_UP;

        // add to canvas;
        int addResult = cv.AddShape(s);
        if(addResult == ERROR_OUT_OF_CANVAS)
          cout << "ERROR OUT OF CANVAS" << endl;
      }
    } // end of "add";
    else if(command == "delete") {
      // get a shape -> delete -> if invalid index -> ignore;
      int index;
      cin >> index;
      cv.DeleteShape(index);
    }
    else if(command == "draw") {
      // draw;
      cv.Draw(cout);
    }
    else if(command == "dump") {
      // dump;
      cv.Dump(cout);
    }
    else {
      break;
    }
  } // end of while loop;

  return 0;
}
