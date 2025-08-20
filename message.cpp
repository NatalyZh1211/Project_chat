#include <iostream>
#include "message.h"
using namespace std;

message::message(int ab_num_from, int ab_num_to, string str)
    : _ab_num_from(ab_num_from), _ab_num_to(ab_num_to), _str(str)
{}

message::message() = default;

int message::getNumTo() { return _ab_num_to; }
void message::setNumTo(int num) { _ab_num_to = num; }
int message::getNumFrom() { return _ab_num_from; }
void message::setNumFrom(int num) { _ab_num_from = num; }
string message::getMessage() { return _str; }
void message::setMessage(string str) { _str = str; }

chat::chat() : max_num_messages(100), num_messages(0)
{
    MessageArray = new message[max_num_messages];
}

chat::~chat()
{
    delete[] MessageArray;
}

message* chat::getAddress()
{
    return MessageArray;
}

int chat::getMesCount()
{
    return num_messages;
}

void chat::SentToOne(int numFrom, int numTo, string str)
{
    if (num_messages >= max_num_messages) {
        cout << "Достигнуто максимальное количество сообщений" << endl;
        return;
    }
    MessageArray[num_messages] = message(numFrom, numTo, str);
    num_messages++;
}

void chat::SentToAll(int numFrom, int count, string str)
{
    for (int i = 0; i < count && num_messages < max_num_messages; ++i) {
        MessageArray[num_messages] = message(numFrom, i, str);
        num_messages++;
    }
}

void chat::DeleteMessage()
{
    if (num_messages > 0)
        num_messages--;
    else
        cout << "Нет сообщений для удаления" << endl;
}

void chat::ReceiveFrom(int numFrom, int numTo)
{
    bool found = false;
    for (int i = 0; i < num_messages; ++i) {
        message& mes = MessageArray[i];
        if (mes.getNumFrom() == numFrom && mes.getNumTo() == numTo) {
            cout << "От " << numFrom << ": " << mes.getMessage() << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Нет сообщений от этого пользователя" << endl;
}

void chat::ReceiveAll(int numTo)
{
    bool found = false;
    for (int i = 0; i < num_messages; ++i) {
        message& mes = MessageArray[i];
        if (mes.getNumTo() == numTo) {
            cout << "От абонента " << mes.getNumFrom() << ": " << mes.getMessage() << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Нет входящих сообщений" << endl;
}