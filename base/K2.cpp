#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long int;
using graph = vector<vector<int>>;
const int INF = 1e9;

void bfs(const graph& g, int u, vector<int>& d, vector<int>& prev) {
    int n = g.size();
    d.resize(n, INF);
    prev.resize(n, -1);
    d[u] = 0;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (d[v] < INF) {
                continue;
            }
            prev[v] = u;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    graph g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> d, prev;
    bfs(g, k - 1, d, prev);
    for (int elem : d) {
        if (elem == INF) {
            cout << -1 << ' ';
            continue;
        }
        cout << elem << ' ';
    }
}