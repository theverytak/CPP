// draw_shape_main.cc
// 2016. 7. 30

#include "draw_shape.h"

int main() {
  vector<Shape*> shapes;
  size_t row, col;
  cin >> row >> col;
  Canvas cv(row, col);
  cout << cv;
  while (true) {
    string cmd;
    cin >> cmd;
    if (cmd == "add") {
      string type;
      cin >> type;
      if (type == "rect") {
          Rectangle* shape = new Rectangle();
          cin >> *shape;
          shapes.push_back(shape);
      }
      else if (type == "tri_up") {
          UpTriangle* shape= new UpTriangle();
          cin >> *shape;
          shapes.push_back(shape);
      }
      else if (type == "tri_down") {
          DownTriangle* shape = new DownTriangle();
          cin >> *shape;
          shapes.push_back(shape);
      }
      else if (type == "diamond") {
          Diamond* diamond = new Diamond();
          cin >> *diamond;
          shapes.push_back(diamond);
      }
      else continue;
    } else if (cmd == "draw") {
      cv.Clear();
      for (int i = 0; i < shapes.size(); ++i) shapes[i]->Draw(&cv);
      cout << cv;
    } else if (cmd == "delete") {
      int index;
      cin >> index;
      if(index < shapes.size()) shapes.erase(shapes.begin()+index);
    } else if (cmd == "dump") {
      for(int i=0;i<shapes.size();i++){
          if(shapes[i]->type()=="rect")
              cout << i << ' '<< "rect" <<' '<< shapes[i]->x() << ' '
                   << shapes[i]->y() << ' ' << shapes[i]->w() << ' '
                   << shapes[i]->h() << ' ' << shapes[i]->brush() << endl;
          else
              cout << i <<' ' <<shapes[i]->type() << ' ' <<shapes[i]->x()
                   << ' ' << shapes[i]->y() << ' '  << shapes[i]->h() << ' '
                   << shapes[i]->brush() << endl;
      }
    } else if (cmd == "resize") {
        int row,col;
        cin >> row >> col;
        cv.Resize(row,col);
    } else {
      break;
    }
  }
  for (int i = 0; i < shapes.size(); ++i) delete shapes[i];
  shapes.clear();

  return 0;
}
