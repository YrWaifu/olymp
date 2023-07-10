#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long int;

struct elem {
    ll l, r;
    elem() = default;
    elem(ll _l, ll _r) : l(_l), r(_r) {}
};

bool comparator(const elem& a, const elem& b){
    if(a.r != b.r){
        return a.r < b.r;
    }
    else{
        return a.l > b.l;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<elem> parts;
    for (int i = 0; i < n; ++i) {
        ll l, r;
        cin >> l >> r;
        parts.emplace_back(l, r);
    }
    sort(parts.begin(), parts.end(), comparator);
    ll edges = (parts.begin())->r;
    ll res = 1;
    for (elem elem : parts) {
        if (elem.l >= edges) {
            edges = elem.r;
            res += 1;
        }
    }
    cout << res;
}