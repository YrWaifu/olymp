#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

class item {
    // private изначально
    public:
    int num;
    char word;
};
// struct - изначально все паблик

bool operator<(item a, item b) {
    return a.num < b.num;
}

int main() {
    int n;
    cin >> n;
    vector<item> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].num >> a[i].word;
    }
    for (item elem : a) {
        // cout << elem.num << ' ' << elem.word << '\n';
    }
}