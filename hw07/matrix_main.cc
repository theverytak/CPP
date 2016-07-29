// matrix_main.cc
// 2016. 7. 29

#include "matrix.h"

int main() {
  map<string, Matrix> matrices;
  string cmd;
  while (cmd != "quit") {
    cin >> cmd;
    if (cmd == "matrix") {
      string name;
      Matrix mat;
      cin >> name >> mat;
      matrices[name] = mat;
      cout << name << ":" << endl << mat;
    } else if (cmd == "list") {
      for (map<string, Matrix>::const_iterator it = matrices.begin();
           it != matrices.end(); ++it) {
        cout << it->first << " "
             << it->second.rows() << " " << it->second.cols() << endl;
      }
    } else if (cmd == "print") {
      string str;
      cin >> str;
      Matrix mat;
      if (ParseMatrix(matrices, str, &mat)) cout << mat;
      else cout << atoi(str.c_str()) << endl;         // in this case, input mat is a number
    } else if (cmd == "eval") {
      string lhs, op, rhs;
      cin >> lhs >> op >> rhs;
      Matrix lmat, rmat;
      bool left = ParseMatrix(matrices, lhs, &lmat);
      bool right = ParseMatrix(matrices, rhs, &rmat);
      int lval = left ? 0 : atoi(lhs.c_str());
      int rval = right ? 0 : atoi(rhs.c_str());
      if (left && right) {    // mat, mat
        if (op == "+") cout << (lmat + rmat);
        else if (op == "-") cout << (lmat - rmat);
        else if (op == "*") cout << (lmat * rmat);
        else cout << "Invalid operator " << op << endl;
      } else if (left) {    // mat, num
        if (op == "+") cout << (lmat + rval);
        else if (op == "-") cout << (lmat - rval);
        else if (op == "*") cout << (lmat * rval);
        else cout << "Invalid operator " << op << endl;
      } else if (right) {   // num, mat
        if (op == "+") cout << (lval + rmat);
        else if (op == "-") cout << (lval - rmat);
        else if (op == "*") cout << (lval * rmat);
        else cout << "Invalid operator " << op << endl;
      } else {              // num, num
        if (op == "+") cout << (lval + rval) << endl;
        else if (op == "-") cout << (lval - rval) << endl;
        else if (op == "*") cout << (lval * rval) << endl;
        else cout << "Invalid operator " << op << endl;
      }
    }
  }
  return 0;
}
