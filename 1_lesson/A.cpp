#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0, l = 0, r = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (true) {
        cin >> l >> r;
        if (l == 0 and r == 0) break;
        reverse(a.begin() + l - 1, a.begin() + r);
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }

}