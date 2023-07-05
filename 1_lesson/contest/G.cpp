#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int intersect(int x1, int x2, int x3, int x4) {
    if (x1 > x3) {
        swap(x1, x3);
        swap(x2, x4);
    }
    if (x1 > x2) {
        swap(x1, x2);
    }
    if (x3 > x4) {
        swap(x3, x4);
    }
    if (x2 < x3) {
        return 0;
    }
    return min(x2, x4) - max(x1, x3);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    int ans = abs(x1 - x2) * abs(y1 - y2) + abs(x3 - x4) * abs(y3 - y4) - intersect(x1, x2, x3, x4) * intersect(y1, y2, y3, y4);
    cout << ans << endl;
}