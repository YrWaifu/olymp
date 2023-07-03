#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
 
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
 
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
 
        int k = 0;
        bool flag = false;
        while (!flag) {
            flag = true;
            for (int j = 0; j < n - 1; j++) {
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                    k++;
                    flag = false;
                }
            }
        }
 
        cout << k << endl;
    }
 
    return 0;
}