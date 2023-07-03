#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n = 0;
    cin >> n;
    long long res = 1;
    for (int i = 1; i <= n; i++) {
        res = (res * i) % 1000000007;
    }
    cout << res << '\n';
}