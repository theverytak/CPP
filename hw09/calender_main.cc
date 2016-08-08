// calender_main.cc
// 2016. 8. 8

#include "calender.h"

int main() {

  Date calender;
  string cmd;

  while(true) {
    cin >> cmd;
    if(cmd == "set") {
      try {
      cin >> calender;
      } catch (InvalidDateException invalid) {
        cout << "Invalid date: " << invalid.input_date << endl;
        continue;
      }
      cout << calender;
    } else if(cmd == "next_day") {
      calender.NextDay();
      cout << calender;
    } else if(cmd == "next") {
      int days;
      cin >> days;
      calender.NextDay(days);
      cout << calender;
    } else {
      break;
    }
  }

  return 0;
}
