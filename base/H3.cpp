#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long int;

struct event {
    int pos, val;

    event() = default;

    event(int _pos, int _val) : pos(_pos), val(_val) {} // cписок инициализации
};

bool comp(const event& a, const event& b) {
    if (a.pos != b.pos) {
        return a.pos < b.pos;
    } else {
        return a.val < b.val;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<event> e;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        e.emplace_back(l, 1);
        e.emplace_back(r + 1, -1);
    }
    sort(all(e), comp);
    event ans(-1, -1);
    int cnt = 0;
    for (event elem : e) {
        cnt += elem.val;
        if (cnt > ans.val) {
            ans.pos = elem.pos;
            ans.val = cnt;
        }
    }
    cout << ans.val << ' ' << ans.pos << endl;
}