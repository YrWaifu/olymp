#include <bits/stdc++.h>

using ll = int64_t;

#define all(x) x.begin(), x.end()

using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

using namespace std;

const ll INF = 1e18;

using item = pair<ll, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n, vector<ll>(n));
    for (int i = 0; i <m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u;
        --v;
        g[u][v] = w;
    }
    for (int u = 0; u < n; ++u) {
        g[u][u] = 0;
    }
    for (int k = 0; k < n; ++k) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; v++) {
                g[u][v] = min(g[u][v], g[u][k] + g[k][v]);
            }
        }
    }
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; ++v) {
            if (g[u][v] < INF) {
                cout << g[u][v] << ' ';
            } else {
                cout << "inf ";
            }
        }
        cout << '\n';
    }
}