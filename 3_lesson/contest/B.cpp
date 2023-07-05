#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> dp(n + 1);
    vector<int> alarm(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < m; i++) {
        int buf;
        cin >> buf;
        alarm[buf] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0 and alarm[i - j] != 1) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;
}
