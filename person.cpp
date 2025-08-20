#include <iostream>
#include "person.h"
using namespace std;

person::person() : _login(""), _password("12345678"), _name(""), _person_number(0), _avtorized(false)
{}

person::person(string login, string password, string name, int person_number, bool avtorized)
    : _login(login), _password(password), _name(name), _person_number(person_number), _avtorized(avtorized)
{}

string person::getName() { return _name; }
string person::getPassword() { return _password; }
void person::setPassword(string pass) { _password = pass; }
string person::getLogin() { return _login; }
int person::getNumber() { return _person_number; }
bool person::getAvtorized() { return _avtorized; }
void person::setAvtorized(bool avt) { _avtorized = avt; }

PersonArray::PersonArray(int max_person_number)
    : _max_person_number(max_person_number), _person_count(0)
{
    _person_array = new person[_max_person_number];
    for (int i = 0; i < _max_person_number; ++i) {
        _person_array[i] = person("", "12345678", "", i, false);
    }
}

PersonArray::~PersonArray()
{
    delete[] _person_array; // ✅ delete[] для массива
}

void PersonArray::getInfoPersonArray()
{
    if (_person_count == 0) {
        cout << "В чате пока нет зарегистрированных пользователей" << endl;
    }
    else {
        for (int i = 0; i < _person_count; ++i) {
            cout << i << " : Логин: " << _person_array[i].getLogin()
                << " Имя: " << _person_array[i].getName() << endl;
        }
    }
    cout << endl;
}

int PersonArray::getPersonCount()
{
    return _person_count;
}

bool PersonArray::Registrate(string str)
{
    for (int i = 0; i < _person_count; ++i) {
        if (_person_array[i].getLogin() == str)
            return true;
    }
    return false;
}

void PersonArray::addPerson()
{
    if (_person_count >= _max_person_number) {
        cout << "Превышено максимальное количество пользователей чата" << endl;
        return;
    }

    cout << "Регистрация пользователя" << endl;
    cout << "Введите логин: ";
    string login;
    cin >> login;

    while (Registrate(login)) {
        cout << "Пользователь с таким логином уже существует. Введите другой: ";
        cin >> login;
    }

    cout << "Введите имя: ";
    string name;
    cin >> name;

    string password;
    cout << "Введите пароль из 8 символов: ";
    while (true) {
        cin >> password;
        if (password.length() == 8) break;
        cout << "Пароль должен быть 8 символов. Повторите: ";
    }

    _person_array[_person_count] = person(login, password, name, _person_count, false);
    _person_count++;
    cout << "Пользователь добавлен" << endl;
}

void PersonArray::Avtorize()
{
    cout << "Авторизация" << endl;
    if (_person_count == 0) {
        cout << "В чате пока нет пользователей. Регистрируйтесь!" << endl;
        addPerson();
        _person_array[0].setAvtorized(true);
        cout << "Пользователь авторизован" << endl;
        return;
    }

    cout << "Введите логин: ";
    string login;
    cin >> login;
    cout << "Введите пароль: ";
    string pass;
    cin >> pass;

    bool found = false;
    for (int i = 0; i < _person_count; ++i) {
        if (_person_array[i].getLogin() == login) {
            found = true;
            while (_person_array[i].getPassword() != pass) {
                cout << "Неверный пароль. Попробуйте снова: ";
                cin >> pass;
            }
            _person_array[i].setAvtorized(true);
            cout << "Пользователь авторизован" << endl;
            return;
        }
    }
    if (!found)
        cout << "Пользователь с таким логином не найден" << endl;
}

void PersonArray::Exit()
{
    for (int i = 0; i < _person_count; ++i)
        _person_array[i].setAvtorized(false);
    cout << "Вы вышли из чата" << endl;
}

int PersonArray::getNumAvtorized()
{
    for (int i = 0; i < _person_count; ++i) {
        if (_person_array[i].getAvtorized())
            return i;
    }
    cout << "Нет авторизованных пользователей" << endl;
    return -1; // ❌
}

void PersonArray::ChangePassword()
{
    cout << "Сменить пароль? (1 - да, 0 - нет): ";
    string answer;
    cin >> answer;
    if (answer != "1") return;

    int idx = -1;
    for (int i = 0; i < _person_count; ++i) {
        if (_person_array[i].getAvtorized()) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        cout << "Нет авторизованного пользователя" << endl;
        return;
    }

    string new_pass;
    cout << "Введите новый 8-символьный пароль: ";
    while (true) {
        cin >> new_pass;
        if (new_pass.length() == 8) break;
        cout << "Пароль должен быть 8 символов. Повторите: ";
    }

    _person_array[idx].setPassword(new_pass);
    cout << "Пароль изменён" << endl;
}

void PersonArray::deletePerson()
{
    cout << "Удалить аккаунт? (1 - да, 0 - нет): ";
    string answer;
    cin >> answer;
    if (answer != "1") return;

    int idx = -1;
    for (int i = 0; i < _person_count; ++i) {
        if (_person_array[i].getAvtorized()) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        cout << "Нет авторизованного пользователя" << endl;
        return;
    }

    for (int i = idx; i < _person_count - 1; ++i)
        _person_array[i] = _person_array[i + 1];

    _person_count--;
    cout << "Пользователь удалён" << endl;
}