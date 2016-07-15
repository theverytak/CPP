// reply_admin.h
// 2017. 7. 15


#ifndef _REPLY_ADMIN_H_
#define _REPLY_ADMIN_H_

#define NUM_OF_CHAT 200

#include <iostream>
#include <string>
using namespace std;

class ReplyAdmin
{
private:
    string* chats;

    int getChatCount();

public:
    ReplyAdmin();
    ~ReplyAdmin();

    bool addChat(string _chat);
    bool removeChat(int _index);                // #remove #
    bool removeChat(int *_indices, int _count); // #remove #,#,#,#
    bool removeChat(int _start, int _end);      // #remove #-#
    void printChat();
};

#endif // _REPLY_ADMIN_H_
