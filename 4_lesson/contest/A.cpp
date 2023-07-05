#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < q; ++i) {
        int l, r, v;
        cin >> l >> r >> v;
        a[l - 1] += v;
        if (r < n) {
            a[r] -= v;
        }
    }
    for (int i = 1; i < n; ++i) {
        a[i] += a[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
}