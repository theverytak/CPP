// grader.h
// 2016. 8. 8

#ifndef _GRADER_H_
#define _GRADER_H_

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Subject {
 public:
  Subject(const string& name, int credit)
      : name_(name), credit_(credit) {}
  virtual ~Subject() {}

  const string& name() const { return name_; }
  int credit() const { return credit_; }
  virtual string GetGrade(int score) const = 0;

 private:
  string name_;
  int credit_;
};

// 성적을 Pass / Fail 로 구분하여 출력해주는 클래스.
// 성적이 pass_score보다 같거나 높으면 "P", 아니면 "F"를 리턴.
class SubjectPassFail : public Subject {
 public:
  SubjectPassFail(const string& name, int credit, int pass_score);
  virtual ~SubjectPassFail() {}

  virtual string GetGrade(int score) const;

 private:
  int pass_score_;
};

// 성적을 A, B, C, D, F 로 구분하여 출력해주는 클래스.
// 성적이 속하는 구간에 따라
// 100 >= "A" >= cutA > "B" >= cutB > "C" >= cutC > "D" >= cutD > "F".
class SubjectGrade : public Subject {
 public:
  SubjectGrade(const string& name, int credit,
               int cutA, int cutB, int cutC, int cutD);
  virtual ~SubjectGrade() {}

  virtual string GetGrade(int score) const;

 private:
  int cutA_, cutB_, cutC_, cutD_;
};


#endif  // _GRADER_H_
