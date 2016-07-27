// parse_radix_main.cc
// 2017. 7. 27

#include "parse_radix.h"

int main() {
  while(true) {
    string command;
    cin >> command;
    if(command == "eval") {
      string strLhs, strRhs, operand, strRes;
      int lhs, rhs, radix, res;

      // input data after "eval", before radix;
      cin >> strLhs >> operand >> strRhs;

      // make lhs and rhs;
      lhs = parseRadix(strLhs);
      rhs = parseRadix(strRhs);


      if(operand == "==" || operand == "<" || operand == ">") {  // comparison;
        // error case;
        if(lhs < 0 || rhs < 0) {
          cout << "error" << endl;
          continue;
        }
        // return true or false
        if(compare(lhs, rhs, operand))
          strRes = "true";
        else
          strRes = "false";
      }
      else if(operand == "+" || operand == "-" || operand == "*" ||
              operand == "/"){    // calculation;
        cin >> radix;
        // error case;
        if(lhs < 0 || rhs < 0) {
          cout << "error" << endl;
          continue;
        }
        // calculation part;
        res = calculate(lhs, rhs, operand);
        strRes = convertRadix(res, radix);
      }
      else
        strRes = "error";

      cout << strRes << endl;
    }   // end of if;

    else
      break;

  }
  return 0;
}
