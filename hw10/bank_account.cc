// bank_account.cc
// 2016. 8. 9

#include "bank_account.h"

unsigned int Account::ComputeExpectedBalance(unsigned int n_years_later) const {
	return balance() + balance() * interest_rate() * n_years_later;
}

unsigned int SavingAccount::ComputeExpectedBalance(unsigned int n_years_later) const {
	double result = balance();

	for (int i = 0; i < n_years_later; i++)
		result += result * interest_rate();

	return result;
}

bool SaveAccounts(const vector<Account*>& accounts, const string& filename) {
	ofstream outfile;
	outfile.open(filename.c_str());

	if (!outfile.good()) {
		outfile.close();

		return false;
	}

	for (int i = 0; i < accounts.size(); i++)
		outfile << accounts[i]->name() << "\t" << accounts[i]->type() << "\t"
		<< accounts[i]->balance() << "\t" << accounts[i]->interest_rate() << endl;

	outfile.close();

	return true;
}

bool LoadAccounts(const string& filename, vector<Account*>* accounts) {
	ifstream infile;
	infile.open(filename.c_str());

	if (!infile.good()) {
		cout << "file open failure" << endl;
		infile.close();

		return false;
	}

	string name, type;
	int balance;
	double rate;
	Account* ac;

	infile >> name >> type >> balance >> rate;

	if (type == "checking")
		ac = new Account(name, balance, rate);

	else if (type == "saving")
		ac = new Account(name, balance, rate);

	accounts->push_back(ac);

	infile.close();

	return true;
}
