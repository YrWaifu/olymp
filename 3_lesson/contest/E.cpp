#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> dp(n + 1, LLONG_MAX);
    dp[1] = 0;
    for (ll i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + i;
        if (i % 2 == 0 and i / 2 >= 1) {
            dp[i] = min(dp[i], dp[i / 2] + i);
        }
        if (i % 3 == 0 and i / 3 >= 1) {
            dp[i] = min(dp[i], dp[i / 3] + i);
        }
    }
    cout << dp[n] << '\n';
}   