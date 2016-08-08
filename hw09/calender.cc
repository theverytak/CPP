// calender.cc
// 2016. 8. 8

#include "calender.h"

int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void Date::NextDay(int n) {
  int days = n + ComputeDaysFromYearStart(year_, month_, day_);

  if(days <= 0) {
    year_--;
    days += GetDaysInYear(year_);
  }
  else if(days > GetDaysInYear(year_)) {
    days -= GetDaysInYear(year_);
    year_++;
  }

  for(int i = 0; i < 12; i++) {
    if(days > daysInMonth[i]) {
      if(i == 1 && LeapYear(year_))
        days--;
      days -= daysInMonth[i];
    } else {
      month_ = i + 1;
      break;
    }
  }

  day_ = days;
}

bool Date::SetDate(int year, int month, int day) {
  if(month <= 0 || day <= 0)
    return false;

  if(day > daysInMonth[month - 1] && !LeapYear(year))
    return false;

  if(LeapYear(year) && month == 2 && day > 29)
    return false;

  year_ = year;
  month_ = month;
  day_ = day;

  return true;
}

int Date::GetDaysInYear(int year) {
  if(LeapYear(year))
    return 366;

  return 365;
}

int Date::ComputeDaysFromYearStart(int year, int month, int day) {
  int days = 0;

  if(month >= 3 && LeapYear(year))
    days++;

  for(int i = 0; i < month - 1; i++)
    days += daysInMonth[i];

  days += day;

  return days;
}

ostream& operator<<(ostream& os, const Date& c) {
  os << c.year() << "." << c.month() << "." << c.day() << endl;

  return os;
}

istream& operator>>(istream& is, Date& c) {
  string today;
  is >> today;
  int year, month, day;
  parseYMD(today, year, month, day);

  if(!c.SetDate(year, month, day))
    throw InvalidDateException(today);

  return is;
}

void parseYMD(string today, int& year, int& month, int& day) {
  int firstDot, secondDot;

  for(int i = 0; i < today.length(); i++) {
    if(today[i] == '.') {
      firstDot = i;
      break;
    }
  }

  for(int i = firstDot + 1; i < today.length(); i++) {
    if(today[i] == '.') {
      secondDot = i;
      break;
    }
  }

  string::size_type sz;

  year = stoi(string(today.begin(), today.begin() + firstDot), &sz);
  month = stoi(string(today.begin() + firstDot + 1, today.begin() + secondDot),
               &sz);
  day = stoi(string(today.begin() + secondDot + 1, today.end()), &sz);
}

bool LeapYear(int year) {
  if(year % 4  == 0 && year % 100 != 0)
    return true;

  if(year % 100 == 0 && year % 400 == 0)
    return true;

  return false;
}
