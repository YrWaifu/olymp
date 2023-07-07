#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long int;
using graph = vector<vector<int>>;

bool dfs(int node, vector<bool>& visited, graph& graph, int target, vector<int>& path) {
    visited[node] = true;
    path.push_back(node);

    if (node == target) {
        return true;
    }

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, visited, graph, target, path)) {
                return true;
            }
        }
    }

    path.pop_back();
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, u, v;
    cin >> n >> m >> u >> v;

    graph edges(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[i] = {a, b};
    }

    graph graph(n + 1);
    vector<bool> visited(n + 1, false);

    for (auto edge : edges) {
        int a = edge[0];
        int b = edge[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> path;
    if (dfs(u, visited, graph, v, path)) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
