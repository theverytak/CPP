// bank_account_main.cc
// 2016. 8. 8

#include "bank_account.h"

int main() {
  string cmd;
  vector<Account* > bank;
  while(cmd != "quit") {
    if(cmd == "add") {
      string name, type;
      int balance;
      double rate;
      Account* ac;

      cin >> name >> type >> balance >> rate;

      if(type == "checking")
        ac = new Account(name, balance, rate);
      else if(type == "saving")
        ac = new SavingAccount(name, balance, rate);

      bank.push_back(ac);
    }
    else if(cmd == "delete") {
      string name;
      cin >> name;

      for(int i = 0; i < bank.size(); i++) {
        if(bank[i]->name() == name)
          bank.erase(bank.begin() + i);
      }
    }
    else if(cmd == "show") {
      for(int i = 0; i < bank.size(); i++) {
        cout << bank[i]->name() << "\t" << bank[i]->type() << "\t"
             << bank[i]->balance() << "\t" << bank[i]->interest_rate() << endl;
      }
    }
    else if(cmd == "after") {
      int year;
      cin >> year;

      for(int i = 0; i < bank.size(); i++) {
        cout << bank[i]->name() << "\t" << bank[i]->type() << "\t"
             << bank[i]->ComputeExpectedBalance(year) << "\t"
             << bank[i]->interest_rate() << endl;
      }
    }
    else if(cmd == "save") {
      string filename;
      cin >> filename;
      SaveAccounts(bank, filename);
    }
    else if(cmd == "load") {
      string filename;
      cin >> filename;
      LoadAccounts(filename, &bank);
    }
  }

  return 0;
}
