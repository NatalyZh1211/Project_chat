#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
using namespace std;

class message
{
public:
    message(int ab_num_from, int ab_num_to, string str);
    message();
    ~message() = default;
    int getNumTo();
    int getNumFrom();
    void setNumTo(int num);
    void setNumFrom(int num);
    string getMessage();
    void setMessage(string str);

private:
    int _ab_num_to;
    int _ab_num_from;
    string _str;
};

class chat
{
public:
    message* getAddress();
    int getMesCount();
    chat();
    ~chat();
    void SentToOne(int numFrom, int numTo, string str);
    void SentToAll(int numFrom, int count, string str);
    void DeleteMessage();
    void ReceiveFrom(int numFrom, int numTo);
    void ReceiveAll(int numTo);

private:
    message* MessageArray;
    int max_num_messages;
    int num_messages;
};

#endif // MESSAGE_H