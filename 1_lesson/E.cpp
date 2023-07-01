#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;
    cin >> a;
    int k = 0;
    for (char elem : a) {
        if ((elem - '0') == 0) {
            k += 1;
        }
        else if ((elem - '0') == 4) {
            k += 1;
        }
        else if ((elem - '0') == 6) {
            k += 1;
        }
        else if ((elem - '0') == 8) {
            k += 2;
        }
        else if ((elem - '0') == 9) {
            k += 1;
        }
    }
    cout << k << '\n';
}
