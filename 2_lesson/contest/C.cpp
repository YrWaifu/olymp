#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    vector<long long> clanSizes(n);
    for (long long i = 0; i < n; ++i) {
        cin >> clanSizes[i];
    }

    priority_queue<long long, vector<long long>, greater<long long>> minHeap(clanSizes.begin(), clanSizes.end());

    for (long long i = 1; i < n; ++i) {
        long long a = minHeap.top();
        minHeap.pop();
        long long b = minHeap.top();
        minHeap.pop();

        cout << a << " " << b << "\n";

        long long summa = a + b;
        minHeap.push(summa);
    }

    return 0;
}
