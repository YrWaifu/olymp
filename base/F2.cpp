#include <bits/stdc++.h>

using namespace std;

vector<int> getLISIndices(const vector<int>& sequence) {
    int n = sequence.size();
    vector<int> dp(n, 1);
    vector<int> prev(n, -1); 
    int maxLen = 1; 
    int endIndex = 0; 

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (sequence[j] < sequence[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }

        if (dp[i] > maxLen) {
            maxLen = dp[i];
            endIndex = i;
        }
    }

    vector<int> lisIndices;
    int currentIndex = endIndex;
    while (currentIndex != -1) {
        lisIndices.push_back(currentIndex);
        currentIndex = prev[currentIndex];
    }

    reverse(lisIndices.begin(), lisIndices.end()); // Инвертируем порядок индексов

    return lisIndices;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> sequence(n);
        for (int i = 0; i < n; i++) {
            cin >> sequence[i];
        }

        vector<int> lisIndices = getLISIndices(sequence);
        int lisLength = lisIndices.size();

        cout << lisLength << endl;
        for (int i = 0; i < lisLength; i++) {
            cout << lisIndices[i] + 1 << " "; // Выводим индексы с 1, так как в задаче индексация начинается с 1
        }
        cout << endl;
    }

    return 0;
}
