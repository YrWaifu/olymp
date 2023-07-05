#include <bits/stdc++.h>

using namespace std;

int count(vector<int>& sticks) {
    int count = 0, n = sticks.size();
    sort(sticks.begin(), sticks.end());
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (sticks[i] + sticks[j] > sticks[k]) {
                    count += 1;
                }
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> sticks(n);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }
    int k = count(sticks);
    cout << k << '\n';
}