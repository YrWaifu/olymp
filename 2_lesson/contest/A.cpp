#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long k = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] == k + 1) {
            k += 1;
        }
        else {
            cout << "Scammed" << '\n';
            return 0;
        }
    }
    cout << "Deck looks good" << '\n';
    return 0;
}