// grader.cc
// 2016. 8. 8

#include "grader.h"

SubjectPassFail::SubjectPassFail(const std::string& name, int credit,
                                 int pass_score) : Subject(name, credit) {
  pass_score_ = pass_score;
}

string SubjectPassFail::GetGrade(int score) const {
  if(score >= pass_score_)
    return "P";

  return "F";
}

SubjectGrade::SubjectGrade(const string& name, int credit,
             int cutA, int cutB, int cutC, int cutD) : Subject(name, credit) {
  cutA_ = cutA;
  cutB_ = cutB;
  cutC_ = cutC;
  cutD_ = cutD;
}

string SubjectGrade::GetGrade(int score) const {
  if(score >= cutA_)
    return "A";

  else if(score >= cutB_)
    return "B";

  else if(score >= cutC_)
    return "C";

  else if(score >= cutD_)
    return "D";

  return "F";
}
