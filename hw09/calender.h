// calender.h
// 2016. 8. 8

#ifndef _CALENDER_H_
#define _CALENDER_H_

#include <iostream>
#include <string>

using namespace std;

class Date {
  public:
    Date() {}
    Date(int year, int month, int day)
      : year_(year), month_(month), day_(day) {}

    void NextDay(int n = 1);
    bool SetDate(int year, int month, int day);
    int year() const { return year_; }
    int month() const { return month_; }
    int day() const { return day_; }

  private:
    // 윤년을 판단하여 주어진 연도에 해당하는 날짜 수(365 또는 366)를 리턴.
    // considering leap year, return the number of days of relevant year;
    static int GetDaysInYear(int year);
    // 해당 날짜가 해당 연도의 처음(1월 1일)부터 며칠째인지를 계산.
    // compute how far is the relevant date from the first day of that year;
    static int ComputeDaysFromYearStart(int year, int month, int day);

    int year_, month_, day_;
};

struct InvalidDateException {
  string input_date;
  InvalidDateException(const string& str) : input_date(str) {}
};

// in form of yyyy.mm.dd input and output;
// if input error occurs, throw InvalidDateException;
ostream& operator<<(ostream& os, const Date& c);
istream& operator>>(istream& is, Date& c);
void parseYMD(string today, int& year, int& month, int& day);
bool LeapYear(int year);

#endif  // _CALENDER_H_
