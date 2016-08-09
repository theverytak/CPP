// grader_main.cc
// 2016. 8. 9

#include "grader.h"

inline bool CompareStudent(const pair<string, double>& a,
	const pair<string, double>& b) {
	if (a.second > b.second)
		return true;

	return false;
}

double GetNumberGrade(const string& str) {
	if (str == "A+") return 4.5;
	if (str == "A" || str == "P") return 4.0;
	if (str == "B+") return 3.5;
	if (str == "B") return 3.0;
	if (str == "C+") return 2.5;
	if (str == "C") return 2.0;
	if (str == "D+") return 1.5;
	if (str == "D") return 1.0;
	return 0.0;
}

int main() {
	string cmd;
	vector<pair<string, double> > student_grades;
	vector<Subject* > subjects;
	int totalCredit = 0;
	while (cmd != "quit") {
		cin >> cmd;
		if (cmd == "subject") {
			string subjectName, subjectType;
			int credit;
			cin >> subjectName >> credit >> subjectType;
			totalCredit += credit;
			if (subjectType == "PF") {
				int cut;
				cin >> cut;
				Subject* sbj = new SubjectPassFail(subjectName, credit, cut);
				subjects.push_back(sbj);
			}
			else {
				int cutA, cutB, cutC, cutD;
				cin >> cutA >> cutB >> cutC >> cutD;
				if (subjectType == "G+") {
					Subject* sbj = new SubjectGrade(subjectName, credit,
													cutA, cutB, cutC, cutD, true);
					subjects.push_back(sbj);
				}
				else if (subjectType == "G") {
					Subject* sbj = new SubjectGrade(subjectName, credit,
													cutA, cutB, cutC, cutD, false);
					subjects.push_back(sbj);
				}
			}
		}
		else if (cmd == "eval") {
			string name;
			int score;
			double averageGrade = 0;
			cin >> name;
			cout << "\t" << name << "\t";
			for (int i = 0; i < subjects.size(); i++) {
				cin >> score;
				string grade = subjects[i]->GetGrade(score);
				cout << grade << "\t";
				averageGrade += GetNumberGrade(grade) * subjects[i]->credit();
			}
			cout << endl;
			averageGrade /= totalCredit;
			student_grades.push_back(make_pair(name, averageGrade));
		}
	}
	sort(student_grades.begin(), student_grades.end(), CompareStudent);
	for (int i = 0; i < student_grades.size(); ++i) {
		cout.precision(3);
		cout << student_grades[i].first << " " << student_grades[i].second << endl;
	}

	for (auto it = subjects.rbegin(); it != subjects.rend(); it++)
		delete *it;
	return 0;
}
