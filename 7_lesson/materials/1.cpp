#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long int;
using pii = pair<int, int>;


vector<int> z_func(const string& s) {
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    int l = -1, r = -1;
    for (int i = l; i < n; ++i) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < n and s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - l > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    vector<int> z = z_func(s);
    for (int elem : z) {
        cout << elem << ' ';
    }
    cout << endl;
}