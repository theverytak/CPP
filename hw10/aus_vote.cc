// aus_vote.cc
// 2016. 8. 8

#include "aus_vote.h"

AusVoteSystem::AusVoteSystem(const vector<string>& candidate_names) {
	for (int i = 0; i < candidate_names.size(); i++) {
		Candidate person;
		person.name = candidate_names[i];
		person.votes = 0;
		candidates.push_back(person);
	}
}

bool AusVoteSystem::AddVote(const vector<int>& vote) {
	if (vote.size() != candidates.size())
		return false;

	Voter v;
	for (int i = 0; i < vote.size(); i++)
		v.votes.push_back(vote[i]);

	voters.push_back(v);

	return true;
}

vector<RoundResult> AusVoteSystem::ComputeResult() {
	vector<RoundResult> result;

	while (true) {
		for (int i = 0; i < candidates.size(); i++)
			if (candidates[i].votes != -1)
				candidates[i].votes = 0;

		for (int i = 0; i < voters.size(); i++)
			candidates[voters[i].votes[0] - 1].votes++;

		result.push_back(candidates);

		int assumedWinner = MostVote();
		if (assumedWinner == -1) break;
		if (candidates[assumedWinner].votes >= voters.size() / 2.0) break;

		EraseLoser();

		if (candidates.empty()) break;
	}

	return result;
}

int AusVoteSystem::MostVote() {
	int index = 0;
	bool allSame = true;

	for (int i = 0; i < candidates.size() - 1; i++) {
		if (candidates[i].votes != candidates[i + 1].votes &&
			candidates[i].votes != -1)
			allSame = false;
	}

	if (allSame) return -1;

	for (int i = 1; i < candidates.size(); i++) {
		if (candidates[index].votes < candidates[i].votes)
			index = i;
	}

	return index;
}

void AusVoteSystem::EraseLoser() {
	int leastVote;

	for (int i = 0; i < candidates.size(); i++) {
		if (candidates[i].votes != -1) {
			leastVote = candidates[i].votes;
			break;
		}
	}

	for (int i = 0; i < candidates.size(); i++) {
		if ((candidates[i].votes != -1) && candidates[i].votes < leastVote)
			leastVote = candidates[i].votes;
	}

	for (int i = 0; i < candidates.size(); i++) {
		if (candidates[i].votes == leastVote)
			candidates[i].votes = -1;
	}

	for (int i = 0; i < voters.size(); i++) {
		for(int j = 0; j < voters[i].votes.size(); j++) 
			if (candidates[voters[i].votes[j] - 1].votes == -1)
				voters[i].votes.erase(voters[i].votes.begin() + j);
	}
}

string AusVoteSystem::Winner() {
	if (MostVote() == -1)
		return "";

	return candidates[MostVote()].name;
}
