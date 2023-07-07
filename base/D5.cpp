#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<string, string> accounts;
    map<string, bool> loggedUsers;

    string s1, s2, s3;
    while (cin >> s1) {
        if (s1 == "register") {
            cin >> s2 >> s3;
            if (accounts.find(s2) == accounts.end()) {
                accounts[s2] = s3;
                loggedUsers[s2] = 0;
                cout << "account created\n";
            } else {
                cout << "login already in use\n";
            }
        } else if (s1 == "login") {
            cin >> s2 >> s3;
            if (accounts.find(s2) == accounts.end() || accounts[s2] != s3) {
                cout << "wrong account info\n";
            } else if (loggedUsers[s2]) {
                cout << "already logged in\n";
            } else {
                loggedUsers[s2] = true;
                cout << "logged in\n";
            }
        } else if (s1 == "logout") {
            cin >> s2;
            if (accounts.find(s2) == accounts.end() || !loggedUsers[s2]) {
                cout << "incorrect operation\n";
            } else {
                loggedUsers[s2] = false;
                cout << "logged out\n";
            }
        }
    }
}