// sorted_array_main.cc
// 2018. 8. 4

#include "sorted_array.h"

typedef SortedArray<int> IntSortedArray;
typedef SortedArray<double> DoubleSortedArray;
typedef SortedArray<string> StringSortedArray;

int main() {
  map<string, IntSortedArray> int_arrays;
  map<string, DoubleSortedArray> double_arrays;
  map<string, StringSortedArray> string_arrays;

  string cmd, str;
  while (cmd != "quit") {
    cin >> cmd;
    if (cmd == "int") {
      IntSortedArray array;
      cin >> str >> array;
      int_arrays[str] = array;
      cout << str << " : " << array << endl;
    } else if (cmd == "double") {
      DoubleSortedArray array;
      cin >> str >> array;
      double_arrays[str] = array;
      cout << str << " : " << array << endl;
    } else if (cmd == "string") {
      StringSortedArray array;
      cin >> str >> array;
      string_arrays[str] = array;
      cout << str << " : " << array << endl;
    } else if (cmd == "list") {
      for (map<string, IntSortedArray>::const_iterator
           it = int_arrays.begin(); it != int_arrays.end(); ++it) {
        cout << "int " << it->first << " : " << it->second << endl;
      }
      for (map<string, DoubleSortedArray>::const_iterator
           it = double_arrays.begin(); it != double_arrays.end(); ++it) {
        cout << "double " << it->first << " : " << it->second << endl;
      }
      for (map<string, StringSortedArray>::const_iterator
           it = string_arrays.begin(); it != string_arrays.end(); ++it) {
        cout << "string " << it->first << " : " << it->second << endl;
      }
    } else if (cmd == "find") {
      cin >> str;
      if (int_arrays.count(str) > 0) {
        int value;
        cin >> value;
        cout << int_arrays[str].Find(value) << endl;
      } else if (double_arrays.count(str) > 0) {
        double value;
        cin >> value;
        cout << double_arrays[str].Find(value) << endl;
      } else if (string_arrays.count(str) > 0) {
        string value;
        cin >> value;
        cout << string_arrays[str].Find(value) << endl;
      }
    }
  }

  return 0;
}
