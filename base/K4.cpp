#include <iostream>
#include <vector>

using namespace std;

// Функция для обхода графа в глубину
void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& parent, vector<int>& cycle) {
    visited[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            parent[neighbor] = node;
            dfs(neighbor, graph, visited, parent, cycle);
        } else if (parent[node] != neighbor) {
            // Найдено обратное ребро, указывающее на цикл
            int current = node;
            while (current != neighbor) {
                cycle.push_back(current);
                current = parent[current];
            }
            cycle.push_back(neighbor);
            cycle.push_back(node);
            return;
        }
    }
}

// Функция для поиска вершин входящих в цикл
vector<int> findCycleNodes(vector<vector<int>>& graph, int n) {
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);
    vector<int> cycle;

    // Запускаем обход в глубину из каждой непосещенной вершины
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, graph, visited, parent, cycle);
        }
    }

    return cycle;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);

    // Считываем ребра графа
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> cycleNodes = findCycleNodes(graph, n);

    // Выводим номера вершин цикла в возрастающем порядке
    for (int node : cycleNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
