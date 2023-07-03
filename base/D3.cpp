#include <bits/stdc++.h>

using namespace std;

struct command
{
    string name;
    int k;
    int fine;
};

bool operator<(command a, command b) {
    if (a.k == b.k) {
        if (a.fine == b.fine) {
            return a.name.size() < b.name.size();
        } else {
            return a.fine < b.fine;
        }
    } else {
        return a.k > b.k; 
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<command> commands(n);
    for (int i = 0; i < n; i++) {
        cin >> commands[i].name >> commands[i].k >> commands[i].fine;
    }
    sort(commands.begin(), commands.end());
    for (int i = 0; i < n; i++) {
        cout << commands[i].name << '\n';
        // cout << ' ' << commands[i].k << ' ' << commands[i].fine;
        // cout << '\n';
    }
}