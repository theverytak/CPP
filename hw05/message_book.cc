// message_book.cc
// 2016. 7. 20

#include "message_book.h"


void MessageBook::AddMessage(int number, const string& message) {
  messages_[number] = message;
}

void MessageBook::DeleteMessage(int number) {
  if(messages_.find(number) != messages_.end())
    messages_.erase(number);
}

vector<int> MessageBook::GetNumbers() const {
  vector<int> numbers;
  for(auto it = messages_.begin(); it != messages_.end(); it++)
    numbers.push_back(it->first);

  return numbers;
}

const string& MessageBook::GetMessage(int number) const {
  static const string empty = "";
  if(messages_.find(number) != messages_.end())
    return Messages()[number];
  else
    return empty;
}
