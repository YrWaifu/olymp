#include <bits/stdc++.h>

using ll = int64_t;

#define all(x) x.begin(), x.end()

using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

using namespace std;

const ll INF = 1e18;

struct wedge {
    int u, v;
    ll w;
    wedge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {};
    
};

using wgraph = vector<vector<wedge>>;

using item = pair<ll, int>;

void dijkstra(int u, const wgraph& g, vector<ll>& d, vector<int>& prev) {
    d[u] = 0;
    int n = g.size();
    set<item> pq;
    for (int i = 0; i < n; i++) {
        pq.insert(make_pair(d[i], i));
    }
    while (!pq.empty()) {
        item cur = *pq.begin();
        pq.erase(pq.begin());
        u = cur.second;
        for (wedge uv : g[u]) {
            int v = uv.w;
            ll w = uv.w;
            if (d[u] + w < d[v]) {
                pq.erase(make_pair(d[v], v));
                d[v] = d[u] + w;
                prev[v] = u;
                pq.insert(make_pair(d[v], v));
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    wgraph g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u;
        --v;
        g[u].emplace_back(u, v, w);
    }
    vector<ll> d(n, INF);
    vector<int> prev(n, -1);
    int start = 0;
    int finish = n - 1;
    dijkstra(start, g, d, prev);
    if (prev[finish] == -1) {
        cout << "-1\n";
        return 0;
    }
    vector<int> path;
    int u = finish;
    while (prev[u] != -1) {
        path.push_back(u);
        u = prev[u];
    } 
    path.push_back(u);
    reverse(all(path));
    for (int elem : path) {
        cout << elem + 1 << ' ';
    }
    cout << endl;
}