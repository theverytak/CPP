// point2d_main.cc
// 2017. 7. 27

#include "point2d.h"

int main() {
  map<char, Point> points;
  string command;

  while(true) {
    cin >> command;
    if(command == "set") {  // set lhs, rhs;
      // input value name, x, y;
      char valName;
      int x, y;
      Point pt;
      cin >> valName >> x >> y;
      pt = Point(x, y);
      // insert the point to map_points;
      points.insert(pair<char, Point>(valName, pt));
    }
    else if(command == "eval") {  // eval and print. input error -> do nothing;
      Point res, lhs, rhs;
      // input lhs, rhs, operand;
      string strLhs, strRhs;
      char operand;
      cin >> strLhs >> operand >> strRhs;

      if(isdigit(strLhs.back())) {
        if(isdigit(strRhs.back())) { // number, number;
          // make lhs;
          string::size_type sz;
          lhs = Point(stoi(strLhs, &sz));
          // make rhs;
          rhs = Point(stoi(strRhs, &sz));
        }
        else {  // number, Point;
          // make lhs;
          string::size_type sz;
          lhs = Point(stoi(strLhs, &sz));
          // make rhs;
          if(strRhs.front() == '-') {  // pre-fix '-' case;
            strRhs.erase(0, 1); // remove '-' from strRhs;
            rhs = -points[strRhs[0]];
          }
          else {    // normal case;
            rhs = points[strRhs[0]];
          }
        }
      }

      else {    // if lhs is not a number;
        if(isdigit(strRhs.back())) { // Point, number;
          // make lhs;
          if(strLhs.front() == '-') {  // pre-fix '-' case;
            strLhs.erase(0, 1);
            if(points.find(strLhs[0]) == points.end()) {
              cout << "input error" << endl;
              continue;
            }
            lhs = -points[strLhs[0]];
          }
          else {  // normal case;
            if(points.find(strLhs[0]) == points.end()) {
              cout << "input error" << endl;
              continue;
            }
            lhs = points[strLhs[0]];
          }
          // make rhs;
          string::size_type sz;
          rhs = Point(stoi(strRhs, &sz));
        }
        else {  // Point, Point;
          // make lhs;
          if(strLhs.front() == '-') {  // pre-fix '-' case;
            strLhs.erase(0, 1);
            if(points.find(strLhs[0]) == points.end()) {
              cout << "input error" << endl;
              continue;
            }
            lhs = -points[strLhs[0]];
          }
          else {  // normal case;
            if(points.find(strLhs[0]) == points.end()) {
              cout << "input error" << endl;
              continue;
            }
            lhs = points[strLhs[0]];
          }
          // make rhs;
          if(strRhs.front() == '-') {  // pre-fix '-' case;
            strRhs.erase(0, 1);
            if(points.find(strRhs[0]) == points.end()) {
              cout << "input error" << endl;
              continue;
            }
            rhs = -points[strRhs[0]];
          }
          else {  // normal case;
            if(points.find(strRhs[0]) == points.end()) {
              cout << "input error" << endl;
              continue;
            }
            rhs = points[strRhs[0]];
          }
        }
      }

      // calc;
      res = Calc(lhs, rhs, operand);
      //print;
      cout << "(" << res.x_ << ", " << res.y_ << ")" << endl;
    }     // end of eval;

    else {
      break;
    }
  }
  return 0;
}
