#include <iostream>
#include <windows.h>
#include "person.h"
#include "message.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "����� ���������� � ���!" << endl;

    chat our_chat;
    PersonArray* pArr = new PersonArray(10);

    bool flag_chat = true;
    while (flag_chat)
    {
        cout << "\n�������� ��������:" << endl;
        cout << "0 - ������������������\n1 - ��������������\n2 - ������� ������\n";
        cout << "3 - ������� �������\n4 - ����� �� ����\n5 - ������� ������������\n";
        cout << "6 - �������� ������\n7 - �������� ����\n8 - ������ �������������\n";
        cout << "9 - �������� �� ������������\n10 - �������� ���\n11 - ������� ���������\n";
        cout << "��� �����: ";

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
            cout << "���� ���������? ������� �����: ";
            pArr->getInfoPersonArray();
            cin >> numTo;
            cout << "������� ���������: ";
            cin.ignore();
            getline(cin, str);
            int numFrom = pArr->getNumAvtorized();
            if (numFrom != -1) our_chat.SentToOne(numFrom, numTo, str);
            break;
        }
        case 7: {
            string str;
            cout << "������� ��������� ����: ";
            cin.ignore();
            getline(cin, str);
            int numFrom = pArr->getNumAvtorized();
            if (numFrom != -1) our_chat.SentToAll(numFrom, pArr->getPersonCount(), str);
            break;
        }
        case 8: pArr->getInfoPersonArray(); break;
        case 9: {
            int numFrom;
            cout << "��������� �� ����? ������� �����: ";
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
            cout << "������� ��������� ���������? (1 - ��): ";
            int choice;
            cin >> choice;
            if (choice == 1) our_chat.DeleteMessage();
            break;
        default:
            cout << "������� ����� �� 0 �� 11" << endl;
        }
    }

    delete pArr;
    cout << "�� ��������!" << endl;
    return 0;
}