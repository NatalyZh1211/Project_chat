#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class person
{
public:
    person();
    person(string login, string password, string name, int person_number, bool avtorized);
    string getName();
    string getPassword();
    void setPassword(string pass);
    string getLogin();
    int getNumber();
    bool getAvtorized();
    void setAvtorized(bool avt);

private:
    string _login;
    string _password;
    string _name;
    int _person_number;
    bool _avtorized;
};

class PersonArray {
private:
    int _max_person_number;
    int _person_count;
    person* _person_array;

public:
    PersonArray(int max_person_number);
    ~PersonArray();
    void getInfoPersonArray();
    int getNumAvtorized();
    void addPerson();
    void ChangePassword();
    void deletePerson();
    bool Registrate(string str);
    void Avtorize();
    void Exit();
    int getPersonCount();
};

#endif // PERSON_H