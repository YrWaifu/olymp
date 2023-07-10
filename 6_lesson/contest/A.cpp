#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
};

void findMaxWidthPaths(int n, int m, int s, const std::vector<std::vector<Edge>>& graph, std::vector<int>& max_widths) {
    max_widths.assign(n + 1, -1);  // Initialize max_widths with -1
    max_widths[s] = 0;  // Width of the start vertex is set to 0

    std::priority_queue<std::pair<int, int>> pq;
    pq.push({0, s});  // Push the start vertex with width 0

    while (!pq.empty()) {
        int width = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (width < max_widths[node]) {
            continue;  // Skip if the current width is less than the max_widths[node]
        }

        for (const Edge& edge : graph[node]) {
            int next_node = edge.to;
            int next_width = std::min(width, edge.weight);

            if (next_width > max_widths[next_node]) {
                max_widths[next_node] = next_width;
                pq.push({next_width, next_node});
            }
        }
    }
}

int main() {
    int n, m, s;
    std::cin >> n >> m >> s;

    std::vector<std::vector<Edge>> graph(n + 1);  // 1-based indexing for vertices
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    std::vector<int> max_widths;
    findMaxWidthPaths(n, m, s, graph, max_widths);

    for (int i = 1; i <= n; ++i) {
        std::cout << max_widths[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
