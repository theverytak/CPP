// world_clock.cc
// 2016. 8. 8

#include "world_clock.h"

map<std::string, int> WorldClock::timezone_;
static ifstream infile;
static ofstream outfile;

void WorldClock::Tick(int seconds) {
  seconds += second() + 60 * minute() + 3600 * hour();
  if(seconds < 0)
    seconds += 60 * 60 * 24;

  hour_ = seconds / 3600;
  hour_ = hour_ % 24;
  seconds = seconds % 3600;

  minute_ = seconds / 60;
  second_ = seconds % 60;
}

bool WorldClock::SetTime(int hour, int minute, int second) {
  if(hour < 0 || hour >= 24)
    return false;

  if(minute < 0 || minute >= 60)
    return false;

  if(second < 0 || second >= 60)
    return false;

  hour_ = hour;
  minute_ = minute;
  second_ = second;

  return true;
}

bool WorldClock::LoadTimezoneFromFile(const string& file_path) {
  string city;
  int diff;
  infile.open(file_path.c_str());
  if(!infile.good() || !outfile.good()) { return false; }
  while(infile.good()) {
    infile >> city >> diff;
    timezone_[city] = diff;
  }

  infile.close();

  return true;
}

void WorldClock::SaveTimezoneToFile(const string& file_path) {
  outfile.open(file_path.c_str());

  for(auto it = timezone_.begin(); it != timezone_.end(); it++) {
    outfile << it->first << " " << it->second << endl;
  }

  outfile.close();
}

void WorldClock::AddTimezoneInfo(const string& city, int diff) {
  timezone_.insert(pair<string, int>(city, diff));
}

ostream& operator<<(ostream& os, const WorldClock& c) {
  if(c.time_difference() == 0)
    os << c.hour() << ":" << c.minute() << ":" << c.second();

  else {
    os << (c.hour() + c.time_difference()) % 24 << ":" << c.minute() << ":"
       << c.second() << "  (+" << c.time_difference() << ")";
  }

  return os;
}

bool WorldClock::SetTimezone(const string& timezone) {
  if(timezone_.find(timezone) == timezone_.end())
    return false;

  time_difference_ = timezone_[timezone];
  return true;
}


istream& operator>>(istream& is, WorldClock& c) {
  int hour, minute, second;
  string hms;

  is >> hms;
  parseHMS(hms, hour, minute, second);

  if(!c.SetTime(hour, minute, second))
    throw InvalidTimeException(hms);

  return is;
}

void parseHMS(string hms, int& hour, int& minute, int& second) {
  int firstColon, secondColon;

  for(int i = 0; i < hms.length(); i++) {
    if(hms[i] == ':') {
      firstColon = i;
      break;
    }
  }

  for(int i = firstColon + 1; i < hms.length(); i++) {
    if(hms[i] == ':') {
      secondColon = i;
      break;
    }
  }

  string::size_type sz;

  hour = stoi(string(hms.begin(), hms.begin() + firstColon), &sz);
  minute = stoi(string(hms.begin() + firstColon + 1, hms.begin() + secondColon),
               &sz);
  second = stoi(string(hms.begin() + secondColon + 1, hms.end()), &sz);
}
