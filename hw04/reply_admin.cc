// reply_admin.cc
// 2017. 7. 19
#include "reply_admin.h"

//constructor & destructor;
ReplyAdmin::ReplyAdmin()
{
  addChat("Hello, Reply Administrator!");
  addChat("I will be a good programmer.");
  addChat("This class is awesome.");
  addChat("Professor Lim is wise.");
  addChat("Two TAs are kind and helpful.");
  addChat("I think male TA looks cool.");
}
ReplyAdmin::~ReplyAdmin()
{
}


// add _chat to the back;
bool ReplyAdmin::addChat(string _chat)
{
  int chatNums = chats.size();

  // return false if the array is full;
  if(chatNums >= NUM_OF_CHAT)
  {
    return false;
  }

  // add the chat to the chat_list;
  chats.push_back(_chat);
  return true;
}


 // #remove #
bool ReplyAdmin::removeChat(int _index)
{
  int chatNums = chats.size();
  list<string>::iterator it = chats.begin();
  advance(it, _index);

  if(_index >= chatNums)
  {
    return false;
  }

  // remove the index;
  chats.erase(it);
  return true;
}


// #remove #,#,#,#
bool ReplyAdmin::removeChat(list<int> _indices)
{
  bool isRemoved = false;

  for(list<int>::reverse_iterator rit = _indices.rbegin(); rit != _indices.rend(); rit++)
  {
    // isRemoved is TRUE even if removing is good only for one time;
    isRemoved = (this->removeChat(*rit) || isRemoved);
  }

  return isRemoved;
}


// #remove #-#
bool ReplyAdmin::removeChat(int _start, int _end)
{
  bool isRemoved = false;

  // adjusting the input range[_start, _end];
  if(_start < 0)
  {
    _start = 0;
  }
  if(_end >= chats.size())
  {
    _end = chats.size();
  }

  for(int i = _end; i >= _start; i--)
  {
    // isRemoved is TRUE even if removing is good only for one time;
    isRemoved = (this->removeChat(i) || isRemoved);
  }

  return isRemoved;
}


// print the whole saved chats;
void ReplyAdmin::printChat()
{
  for(list<string>::iterator it = chats.begin(); it != chats.end(); it++)
  {
    cout << distance(chats.begin(), it) << " " << *it << endl;
  }
}
