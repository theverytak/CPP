// reply_admin.cc
// 2017. 7. 15
#include "reply_admin.h"

//constructor
ReplyAdmin::ReplyAdmin()
{
  chats = new string[NUM_OF_CHAT];
  addChat("Hello, Reply Administrator!");
  addChat("I will be a good programmer.");
  addChat("This class is awesome.");
  addChat("Professor Lim is wise.");
  addChat("Two TAs are kind and helpful.");
  addChat("I think male TA looks cool.");
}


//destructor
ReplyAdmin::~ReplyAdmin()
{
  delete[] chats;
}


int ReplyAdmin::getChatCount()
{
    int i;
    for(i = 0; i < NUM_OF_CHAT; ++i)
    {
        string s = this->chats[i];
        if(s.empty() == true) break;
    }
    return i;
}


bool ReplyAdmin::addChat(string _chat)
{
  int chatNums = this->getChatCount();

  // return false if the array is full;
  if(chatNums >= NUM_OF_CHAT)
  {
    return false;
  }

  // add the chat to the chat_list;
  this->chats[chatNums] = _chat;
  return true;
}


 // #remove #
bool ReplyAdmin::removeChat(int _index)
{
  int chatNums = this->getChatCount();

  if(_index >= chatNums)
  {
    return false;
  }
  // if chats[_index] is an empty string return false;
  if(this->chats[_index] == "")
  {
    return false;
  }

  // remove the index;
  for(int i = _index; i < chatNums - 1; i++)
  {
    this->chats[i] = this->chats[i + 1];
  }
  this->chats[chatNums - 1] = "";
  return true;
}


// #remove #,#,#,#
bool ReplyAdmin::removeChat(int *_indices, int _count)
{
  bool isRemoved = false;

  //i is an index for array named "_indices"
  for(int i = _count - 1; i >= 0; i--)
  {
    // isRemoved is TRUE even if removing is good only for one time;
    isRemoved = (this->removeChat(_indices[i]) || isRemoved);
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
  if(_end >= this->getChatCount())
  {
    _end = this->getChatCount();
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
  for(int i = 0; i < this->getChatCount(); i++)
  {
    cout << i << " " << this->chats[i] << endl;
  }
}
