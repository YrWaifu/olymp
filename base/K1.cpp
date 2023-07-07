#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long int;
using graph = vector<vector<int>>;

void dfs(int node, vector<bool>& visited, graph& graph, vector<int>& traversal, int start) {
    visited[node] = true;
    
    if (node == start) {
        traversal.push_back(0);
    } else {
        traversal.push_back(node);
    }

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph, traversal, start);
        }
    }
}

vector<int> getTraversal(int n, graph& edges, int start) {
    graph graph(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> traversal;

    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(start, visited, graph, traversal, start);

    return traversal;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    graph edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    vector<int> traversal = getTraversal(n, edges, k);

    for (int vertex : traversal) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
