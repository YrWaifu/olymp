#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        grid[x][y] = -1;
    }

    dp[0][0] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (grid[i][j] == -1) {
                dp[i][j] = 0;
            } else {
                if (i > 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j > 0)
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}
