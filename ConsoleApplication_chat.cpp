#include <iostream>
#include <windows.h>
#include "person.h"
#include "message.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Добро пожаловать в чат!" << endl;

    chat our_chat;
    PersonArray* pArr = new PersonArray(10);

    bool flag_chat = true;
    while (flag_chat)
    {
        cout << "\nВыберите действие:" << endl;
        cout << "0 - зарегистрироваться\n1 - авторизоваться\n2 - сменить пароль\n";
        cout << "3 - удалить аккаунт\n4 - выйти из чата\n5 - сменить пользователя\n";
        cout << "6 - написать одному\n7 - написать всем\n8 - список пользователей\n";
        cout << "9 - получить от пользователя\n10 - получить все\n11 - удалить последнее\n";
        cout << "Ваш выбор: ";

        int answ;
        cin >> answ;

        switch (answ) {
        case 0: pArr->addPerson(); break;
        case 1: pArr->Avtorize(); break;
        case 2: pArr->ChangePassword(); break;
        case 3: pArr->deletePerson(); break;
        case 4:
            pArr->Exit();
            flag_chat = false;
            break;
        case 5:
            pArr->Exit();
            pArr->Avtorize();
            break;
        case 6: {
            int numTo;
            string str;
            cout << "Кому отправить? Введите номер: ";
            pArr->getInfoPersonArray();
            cin >> numTo;
            cout << "Введите сообщение: ";
            cin.ignore();
            getline(cin, str);
            int numFrom = pArr->getNumAvtorized();
            if (numFrom != -1) our_chat.SentToOne(numFrom, numTo, str);
            break;
        }
        case 7: {
            string str;
            cout << "Введите сообщение всем: ";
            cin.ignore();
            getline(cin, str);
            int numFrom = pArr->getNumAvtorized();
            if (numFrom != -1) our_chat.SentToAll(numFrom, pArr->getPersonCount(), str);
            break;
        }
        case 8: pArr->getInfoPersonArray(); break;
        case 9: {
            int numFrom;
            cout << "Сообщения от кого? Введите номер: ";
            pArr->getInfoPersonArray();
            cin >> numFrom;
            int numTo = pArr->getNumAvtorized();
            if (numTo != -1) our_chat.ReceiveFrom(numFrom, numTo);
            break;
        }
        case 10: {
            int numTo = pArr->getNumAvtorized();
            if (numTo != -1) our_chat.ReceiveAll(numTo);
            break;
        }
        case 11:
            cout << "Удалить последнее сообщение? (1 - да): ";
            int choice;
            cin >> choice;
            if (choice == 1) our_chat.DeleteMessage();
            break;
        default:
            cout << "Введите число от 0 до 11" << endl;
        }
    }

    delete pArr;
    cout << "До свидания!" << endl;
    return 0;
}