#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

unordered_map<string, string> database;
unordered_map<string, bool> loggedUsers;

void registerUser(const string& login, const string& password) {
    if (database.count(login) > 0) {
        cout << "login already in use" << endl;
    } else {
        database[login] = password;
        cout << "account created" << endl;
    }
}

void loginUser(const string& login, const string& password) {
    if (loggedUsers.count(login) > 0 && loggedUsers[login]) {
        cout << "already logged in" << endl;
    } else if (database.count(login) == 0 || database[login] != password) {
        cout << "wrong account info" << endl;
    } else {
        loggedUsers[login] = true;
        cout << "logged in" << endl;
    }
}

void logoutUser(const string& login) {
    if (loggedUsers.count(login) == 0 || !loggedUsers[login]) {
        cout << "incorrect operation" << endl;
    } else {
        loggedUsers[login] = false;
        cout << "logged out" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string command, login, password;

    while (cin >> command) {
        if (command == "register") {
            cin >> login >> password;
            registerUser(login, password);
        } else if (command == "login") {
            cin >> login >> password;
            loginUser(login, password);
        } else if (command == "logout") {
            cin >> login;
            logoutUser(login);
        }
    }
}