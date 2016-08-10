// aus_vote.h
// 2016. 8. 9

#ifndef _AUS_VOTE_H_
#define _AUS_VOTE_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Candidate {
	string name;
	int votes;
};

struct Voter {
	vector<int> votes;
};

typedef vector<Candidate> RoundResult;

class AusVoteSystem {
public:
	AusVoteSystem(const vector<string>& candidate_names);

	// 후보별 선호도를 1순위부터 입력.
	// 잘못된 숫자가 있거나 선호도 수가 후보자 수와 다르면
	// 해당 입력을 무시하고 false를 리턴.
	bool AddVote(const vector<int>& vote);

	// return the index of the candidate who gets the most vote
	// return -1 if all votes are same but not 0;
	int MostVote();
	void EraseLoser();
	string Winner();

	// 지금까지의 투표를 바탕으로 결과를 모든 라운드에 대해 계산.
	// main() 에서는 vector<RoundResult>를 출력형식에 맞도록 출력.
	vector<RoundResult> ComputeResult();

private:
	// 입력받은 투표를 계산에 적합한 방식으로 저장하는 멤버 변수를 설계.
	vector<Candidate> candidates;
	vector<Voter> voters;
};

#endif  // _AUS_VOTE_H_
