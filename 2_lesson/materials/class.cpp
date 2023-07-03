#include <bits/stdc++.h>

using namespace std;

class item {
    // private изначально
    public:
    int num;
    char word;
    void privet() {
        cout << word;
    }
};
// struct - изначально все паблик

int main() {
    int n;
    cin >> n;
    vector<item> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].num >> a[i].word;
    }
    for (item elem : a) {
        elem.privet();
        // cout << elem.num << ' ' << elem.word << '\n';
    }
}