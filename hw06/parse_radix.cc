// parse_radix.cc
// 2017. 7. 27

#include "parse_radix.h"

// return the result of <, >, ==;
bool compare(int lhs, int rhs, string operand) {
  if(operand == "==")
    return lhs == rhs ? true : false;

  else if(operand == "<")
    return lhs < rhs ? true : false;

  else if(operand == ">")
    return lhs > rhs ? true : false;
}

// return the result of +, -, *, /
int calculate(int lhs, int rhs, string operand) {
  if(operand == "+")
    return lhs + rhs;

  else if(operand == "-")
    return lhs - rhs;

  else if(operand == "*")
    return lhs * rhs;

  else if(operand == "/")
    return lhs / rhs;
}

// ex) "abcde" -> "edcba";
void StringReverse(string *str) {
  string result;
  //std::cout << str << std::endl;
  for(string::reverse_iterator rit=str->rbegin(); rit!=str->rend(); ++rit) {
    //std::cout << *it << " ";
    result += *rit;
  }
  *str = result;
}

// (4, 2) -> "100_2";
string convertRadix(int number, int radix) {
  string result;
  int leftover;
  while(number != 0) {
    leftover = number % radix;
    number /= radix;
    if(leftover < 10)
      result += leftover + '0';
    else
      result += leftover + 'a' - 10;
  }

  StringReverse(&result);
  if(radix != 10)
    result = result + '_' + to_string(radix);
  
  return result;
}
// ex) "ff_16" -> 255;
int parseRadix(const string& numNRadix) {
  int res = 0, radix;
  string strNum;

  // parse number and radix in numNRadix;
  for(auto it = numNRadix.begin(); it != numNRadix.end(); it++) {
    if(*it == '_') {
      strNum = string(numNRadix.begin(), it);
      radix = stoi(string(it + 1, numNRadix.end()));
      break;
    }
  }
  // if there's no "_", radix = 10;
  if(numNRadix.find("_") == string::npos) {
    strNum = numNRadix;
    radix = 10;
  }

  // check if the number is correct one. If its any digit is bigger than radix, return -1;
  for(int i = 0; i < strNum.length(); i++) {
    if(strNum[i] < 'a' && strNum[i] - '0' >= radix)   // if it's a decimal number;
      return -1;

    else if(strNum[i] >= 'a' && strNum[i] - 'a' + 10 >= radix)   // if it's a alphabet;
      return -1;
  }

  // make number;
  for(int i = 0; i < strNum.length(); i++) {
    if(strNum[i] < 'a')
      res += (strNum[i] - '0') *
                 static_cast<int>(pow(radix, strNum.length() - 1 - i));

    else
      res += (strNum[i] - 'a' + 10) *
                 static_cast<int>(pow(radix, strNum.length() - 1 - i));
  }

  return res;
}
