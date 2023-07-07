#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long int;

struct elem {
    ll l, r;
    elem() = default;
    elem(ll _l, ll _r) : l(_l), r(_r) {}
};

bool comp(const elem& a, const elem& b) {
    if (a.r != b.r) {
        return a.r < b.r;
    } else {
        return a.l > b.l;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<elem> parts;
}