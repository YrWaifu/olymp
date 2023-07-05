#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
const ll inf = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<ll> c(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> c[i];
    }
    vector<ll> dp(n + 1, inf);
    dp[0] = 0; 
    vector<ll> prev(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j < 0) {
                break;
            } 
            ll jump = dp[i - j] + c[i];
            if (jump <= dp[i]) {
                dp[i] = jump;
                prev[i] = i - j;
            }
        }
    }
    vector<int> res;
    int u = n;
    while (u > 0) {
        res.push_back(u);
        u = prev[u];
    }
    res.push_back(0);
    reverse(res.begin(), res.end());
    cout << dp[n] << endl;
    cout << res.size() << endl;
    for (int elem : res) {
        cout << elem << ' ';
    }
}