#include <bits/stdc++.h>

using namespace std;

int count(vector<long long>& sticks) {
    int n = sticks.size();
    long long count = 0;
    
    sort(sticks.begin(), sticks.end());
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            long long summa = sticks[i] + sticks[j];
            vector<long long>::iterator lower = lower_bound(sticks.begin(), sticks.end(), summa);
            vector<long long>::iterator start = next(sticks.begin(), j);
            // cout << *start << ' ' << *lower << '\n';
            // cout << (lower - start) << '\n';
            count += (lower - start) - 1;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> sticks(n);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }
    
    int k = count(sticks);
    cout << k << '\n';

}