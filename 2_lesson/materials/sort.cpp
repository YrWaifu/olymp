#include <bits/stdc++.h>

using namespace std;

bool comp(int x, int y) {
    return x > y;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), comp);
    vector<int>::iterator ptr = a.begin();
    cout << a[0] << '\n';
    cout << *(ptr + 2) << '\n';
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}