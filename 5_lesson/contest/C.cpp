#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long int;
using graph = vector<vector<int>>;

void dfs(int node, vector<bool>& visited, graph& graph) {
    visited[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph);
        }
    }
}


int countComponents(int n, graph& edges) {
    graph graph(n + 1); 
    vector<bool> visited(n + 1, false); 
    int components = 0;

    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, visited, graph);
            components++; 
        }
    }

    return components;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    graph edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    int result = countComponents(n, edges);
    cout << result << endl;

    return 0;
}
