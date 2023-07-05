#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int maxx = a[i];
        sum += maxx;

        for (int j = i + 1; j < n; ++j) {
            maxx = max(maxx, a[j]);
            sum += maxx;
        }
    }

    cout << sum << endl;

    return 0;
}
