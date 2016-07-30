// message_book_main.cc
// 2016. 7. 20

#include "message_book.h"

int main() {
  string command;
  MessageBook mb;

  while(true) {
    cin >> command;
    if(command == "add") {
      // get a number and add. if there already exit, replace;
      int number;
      string message;
      cin >> number;
      getline(cin, message);
      message.erase(0, 1);    // deleting first blank space;
      mb.AddMessage(number, message);
    }
    else if(command == "delete") {
      // get a number and delete. if there isn't, ignore;int number;
      int number;
      cin >> number;
      mb.DeleteMessage(number);
    }
    else if(command == "print") {
      // get a number and print. if there isn't print "";
      int number;
      cin >> number;
      cout << mb.GetMessage(number) << endl;
    }
    else if(command == "list") {
      // print all saved messages.
      // use GetNumbers(), and using the return value to call GetMessage();
      vector<int> numbers = mb.GetNumbers();
      for(auto it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << ": " << mb.GetMessage(*it) << endl;
      }
    }
    else {
      break;
    }
  }

  return 0;
}
