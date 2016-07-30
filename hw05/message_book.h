// message_book.h
// 2016. 7. 20

#ifndef _MESSAGE_BOOK_H_
#define _MESSAGE_BOOK_H_
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class MessageBook {

 private:
   map<int, string> messages_;

 public:
  MessageBook() {}
  ~MessageBook() {}
  map<int, string> Messages() const { return messages_; }
  void AddMessage(int number, const string& message);
  void DeleteMessage(int number);
  vector<int> GetNumbers() const;
  const string& GetMessage(int number) const;

};

#endif  // _MESSAGE_BOOK_H_
