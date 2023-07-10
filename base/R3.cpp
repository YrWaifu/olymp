#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()


using namespace std;
using ll = long long int;

const ll MOD = 1e9 + 7;
const ll B = 29;
const int MAX_N = 1e6;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<ll> b_pow(MAX_N + 1);
    b_pow[0] = 1;
    for (int i = 1; i <= MAX_N; ++i) {
        b_pow[i] = (b_pow[i - 1] * B) % MOD;
    }
    string t, p;
    cin >> t >> p;
    int n = t.size();
    int m = p.size();
    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; ++i) {
        pref[i] = (pref[i - 1] * B + t[i - 1] - 'a' + 1) % MOD;
    }
    ll hp = 0;
    for (int i = 0; i < m; i++) {
        hp = (hp * B + p[i] - 'a' + 1) % MOD;
    }
    for (int i = 0; i < n - m + 1; ++i) {
        int l = i + 1;
        int r = (i + m - 1) + 1;
        ll h_sub = (pref[r] - pref[l] * b_pow[l - 1])% MOD;
        if (h_sub < 0) {
            h_sub += MOD;
        }
        if (h_sub == hp) {
            cout << i << endl;
        }
    }
}