#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != a[i + 1]) {
            if (i == n - 2) {
                k += 1;
            }
            k += 1;
        }
    }
    cout << k << '\n';
}