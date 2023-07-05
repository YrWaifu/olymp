#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> dp(n + 1, LLONG_MAX);
    vector<ll> prev(n + 1, -1);
    dp[1] = 0;
    for (ll i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        prev[i] = i - 1;
        if (i % 2 == 0) {
            if (dp[i] > dp[i / 2] + 1) {
                dp[i] = dp[i / 2] + 1;
                prev[i] = i / 2;
            }
        }
        if (i % 3 == 0) {
            if (dp[i] > dp[i / 3] + 1) {
                dp[i] = dp[i / 3] + 1;
                prev[i] = i / 3;
            }
        }
    }
    ll res = 0, m = n;
    for (ll i = 0; i < dp[n]; i++) {
        res += m;
        m = prev[m];
    }
    cout << res;
}