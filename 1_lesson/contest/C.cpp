#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n = 0;
    cin >> n;
    long long l1 = 0, l2 = 1, buf = 0, k = 2;
    int flag = 0;
    if (n == 0 or n == 1) {
        if (n == 0) {
            cout << 0 << '\n';
        }
        else {
            cout << 1 << '\n';
        }
    } else {
        while (l1 < n) {
            buf = l1 + l2;
            if (buf == n) {
                cout << k;
                flag = 1;
                break;
            }
            l1 = l2;
            l2 = buf;
            k += 1;
        }
        if (flag == 0)
            cout << -1 << '\n';
    }
}