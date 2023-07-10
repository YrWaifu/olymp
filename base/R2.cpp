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
    for (int i = 1; i < n; ++i) {
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
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    string s = s2 + "#" + s1;

    vector<int> z = z_func(s);
    int count = 0;
    for (int i = s2.size() + 1; i < z.size(); ++i) {
        if (z[i] == s2.size()) {
            count++;
        }
    }
    
    if (count == 0) {
        cout << "NIE" << endl;
    } else {
        cout << "TAK" << endl;
        cout << count << endl;
    }

    return 0;
}
