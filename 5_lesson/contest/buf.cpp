#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100000;

vector<int> graph[MAXN + 1];
bool visited[MAXN + 1];
int path[MAXN + 1];
int target;
bool found;

void dfs(int u) {
    visited[u] = true;

    for (int v : graph[u]) {
        if (!visited[v]) {
            path[v] = u;

            if (v == target) {
                found = true;
                return;
            }

            dfs(v);

            if (found)
                return;
        }
    }
}

int main() {
    int n, m, u, v;
    cin >> n >> m >> u >> v;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    target = v;
    found = false;
    dfs(u);

    if (!found) {
        cout << -1 << endl;
    } else {
        vector<int> result;
        int curr = target;

        while (curr != u) {
            result.push_back(curr);
            curr = path[curr];
        }

        result.push_back(u);

        for (int i = result.size() - 1; i >= 0; i--) {
            cout << result[i] << " ";
        }

        cout << endl;
    }

    return 0;
}
