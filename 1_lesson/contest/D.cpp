#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 0;
    vector<int> mas = {100, 200, 500, 1000, 5000};
    vector<int> buf = {0, 0, 0, 0, 0};
    cin >> t;
    for (int i = 0; i < t; i++) {
        int k = 0;
        cin >> k;
        for (int j = 4; j >= 0; j--) {
            buf[j] = k / mas[j];
            k = k - (k / mas[j]) * mas[j];
        }
        for (int j = 0; j < 5; j++) {
            cout << buf[j] << ' '; 
        }
        cout << '\n';
    }
}