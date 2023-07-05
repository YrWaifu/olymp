#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l, r;
    cin >> l >> r;

    vector<int> dp(r + 1);
    dp[1] = 1;

    for (int i = 1; i <= r; i++) {
        for (int j = 2 * i; j <= r; j += i) {
            dp[j] = (dp[j] + dp[i]) % MOD;
        }
    }

    int paths = 0;
    for (int i = l; i <= r; i++) {
        paths = (paths + dp[i]) % MOD;
    }

    cout << paths << endl;

    return 0;
}
