#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> gold(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> gold[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = gold[0][0];
    for (int i = 1; i < m; i++) {
        dp[0][i] = dp[0][i - 1] + gold[0][i];
    }
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + gold[i][0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + gold[i][j];
        }
    }

    cout << dp[n - 1][m - 1] << endl;
}