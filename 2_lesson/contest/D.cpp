#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, a;
    cin >> n >> a;
    long long max1 = 0, max2 = 0;

    for (int i = 0; i < n; i++) {
        a = (a * 5) % (1000000000 + 7);
        if (a > max1) {
            max2 = max1;
            max1 = a;
        } else if (a > max2) {
            max2 = a;
        }
    }
    cout << max2 << ' ' << max1 << '\n';
}