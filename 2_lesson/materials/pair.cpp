#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<string, int> mp;
    mp["abc"] = 1;
    mp["abd"] = 2;
    mp["ed"] = 3;
    for (pair<string, int> elem : mp) {
        cout << elem.first << ' ' << elem.second << '\n';
    }
}