#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    set<string> anagramSet;
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;

        sort(word.begin(), word.end());

        anagramSet.insert(word);
    }

    int newSize = anagramSet.size();
    cout << newSize << endl;

    return 0;
}