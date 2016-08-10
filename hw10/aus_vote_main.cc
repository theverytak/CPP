// aus_vote_main.cc
// 2016. 8. 9

#include "aus_vote.h"

int main() {
	vector<string> candidate_names;
	vector<RoundResult> rounds;
	int candidate_num, voter_num;
	
	cin >> candidate_num;
	for (int i = 0; i < candidate_num; i++) {
		string name;
		cin >> name;
		candidate_names.push_back(name);
	}

	AusVoteSystem avs(candidate_names);

	cin >> voter_num;
	for (int i = 0; i < voter_num; i++) {
		vector<int> vote;
		for (int j = 0; j < candidate_num; j++) {
			int preference;
			cin >> preference;
			vote.push_back(preference);
		}
		avs.AddVote(vote);
	}

	rounds = avs.ComputeResult();

	for (int i = 0; i < rounds.size(); i++) {
		cout << "Round " << i + 1 << ": ";
		for (int j = 0; j < rounds[i].size(); j++) {
			if(rounds[i][j].votes != -1)
				cout << rounds[i][j].name << " " << rounds[i][j].votes << " ";
		}
		cout << endl;
	}
	
	cout << "Winner: " << avs.Winner() << endl;
	return 0;
}
