#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long int;
using graph = vector<vector<int>>;

void dfs(int node, vector<bool>& visited, graph& graph, int target, vector<int>& currPath, vector<int>& shortestPath) {
    visited[node] = true;
    currPath.push_back(node);

    if (node == target) {
        if (shortestPath.empty() || currPath < shortestPath) {
            shortestPath = currPath;
        }
    }

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph, target, currPath, shortestPath);
        }
    }

    currPath.pop_back();
    visited[node] = false;
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

    vector<int> currPath;
    vector<int> shortestPath;
    dfs(u, visited, graph, v, currPath, shortestPath);

    if (!shortestPath.empty()) {
        for (int node : shortestPath) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
