// grader.cc
// 2016. 8. 8

#include "grader.h"

SubjectPassFail::SubjectPassFail(const std::string& name, int credit,
	int pass_score) : Subject(name, credit) {
	pass_score_ = pass_score;
}

string SubjectPassFail::GetGrade(int score) const {
	if (score >= pass_score_)
		return "P";

	return "F";
}

SubjectGrade::SubjectGrade(const string& name, int credit,
	int cutA, int cutB, int cutC, int cutD, bool plusType) : Subject(name, credit) {
	cutA_ = cutA;
	cutB_ = cutB;
	cutC_ = cutC;
	cutD_ = cutD;
	plusType_ = plusType;
}

string SubjectGrade::GetGrade(int score) const {
	if (!plusType()) {
		if (score >= cutA_)
			return "A";

		else if (score >= cutB_)
			return "B";

		else if (score >= cutC_)
			return "C";

		else if (score >= cutD_)
			return "D";

		return "F";
	}
	else {
		if (score >= (100 + cutA_) / 2)
			return "A+";

		else if (score >= cutA_)
			return "A";

		else if (score >= (cutA_ + cutB_) / 2)
			return "B+";

		else if (score >= cutB_)
			return "B";

		else if (score >= (cutB_ + cutC_) / 2)
			return "C+";

		else if (score >= cutC_)
			return "C";

		else if (score >= (cutC_ + cutD_) / 2)
			return "D+";

		else if (score >= cutD_)
			return "D";

		return "F";
	}
}
