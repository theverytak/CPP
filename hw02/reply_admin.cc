// reply_admin.cc
// 2016. 7. 13

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

const int NUM_OF_CHAT = 200;

// return the number of chattings in the string array;
int GetChatCount(string *chat_list)
{
    int i;
    for(i = 0; i < NUM_OF_CHAT; ++i)
    {
        string s = chat_list[i];
        if(s.empty() == true) break;
    }
    return i;
}

// print the whole chattings;
void PrintChat(string *chat_list)
{
    int count = GetChatCount(chat_list);
    for(int i = 0; i < count; ++i)
    {
        cout << i << " " << chat_list[i] << endl;
    }
}

 // returns true when adding chat is succeeded;
bool AddChat(string *chat_list, string chat) {
  int count = GetChatCount(chat_list);

  // return false if the array is full;
  if(count >= NUM_OF_CHAT) {
    return false;
  }

  // add the chat to the chat_list;
  chat_list[count] = chat;
  return true;
}

// returns true when removing chat is succeeded;
bool RemoveChat(string *chat_list, int index) {
  int count = GetChatCount(chat_list);

  // if chat_list[index] is an empty string return false;
  if(chat_list[index] == "") {
    return false;
  }

  // remove the index;
  for(int i = index; i < count - 1; i++) {
    chat_list[i] = chat_list[i + 1];
  }
  chat_list[count - 1] = "";
  return true;
}


// Implement commented (/* */) areas in main function
int main(void) {
    string* chats = new string[NUM_OF_CHAT];

    AddChat(chats, "Hello, Reply Administrator!");
    AddChat(chats, "I will be a good programmer.");
    AddChat(chats, "This class is awesome.");
    AddChat(chats, "Professor Lim is wise.");
    AddChat(chats, "Two TAs are kind and helpful.");
    AddChat(chats, "I think male TA looks cool.");

    while(true) {
        string command;
        getline(cin, command);

        if(command == "#quit") {
          break;
        }
        else if(command.find("#remove") != string::npos) {
          string numbers = command.substr(7);
          bool is_removed = true;
          // if there is a ',' in numbers;
          // 1. find the num; 2. erase it; 3. remake the string numbers;
          if(numbers.find(',') != string::npos) {
            int comma_index_start = 0, comma_index_end = 0;
            while(comma_index_end != numbers.length()) {
              // find the ','. if it's found, save the index, else make it the length of numbers so that we can exit the while loop;
              for(int i = comma_index_start; i < numbers.length(); i++) {
                if(numbers[i] == ',') {
                  comma_index_end = i;
                  break;
                }
                if(i == numbers.length() - 1) {
                  comma_index_end = numbers.length();
                }
              }
              string str_num = numbers.substr(comma_index_start, comma_index_end - comma_index_start);
              int num = stoi(str_num);
              is_removed = RemoveChat(chats, num);
              comma_index_start = comma_index_end + 1;
            }
          }
          else if(numbers.find('-') != string::npos) {
            // find num1 and num2 from string numbers;
            int dash_index;
            for(int i = 0; i < numbers.length(); i++) {
              if(numbers[i] == '-') {
                dash_index = i;
                break;
              }
            }
            string str_num1 = numbers.substr(0, dash_index);
            string str_num2 = numbers.substr(numbers.find('-') + 1);
            int num1 = stoi(str_num1);
            int num2 = stoi(str_num2);
            cout << "num : " << num1 << " " << num2 << endl;
            for(int i = num1; i <= num2; i++) {
              is_removed = RemoveChat(chats, i);
            }
          }
          else {
            int num = stoi(numbers);
            is_removed = RemoveChat(chats, num);
          }
          if(is_removed) PrintChat(chats);
        }
        else if(AddChat(chats, command)) {
        PrintChat(chats);
        }
    }

    // delete chatting list
    delete[] chats;

    return 0;
}
