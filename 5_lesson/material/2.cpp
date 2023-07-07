#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long int;
using grid = vector<string>;
const int INF = 1e9;

struct cord {
    int x; 
    int y;
};

bool check(int x, int y, int n, int m) {
    return (0 <= x and x < n) and (0 <= y and y < m);
}

void bfs(const grid& g, cord u, vector<vector<int>>& d) {
    int n = g.size();
    int m = g[0].size();
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int x = u.x, y = u.y;
    d[x][y] = 0;
    queue<cord> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int xn = u.x + dx[i];
            int yn = u.y + dy[i];
            if (!check(xn, yn, n, m)) {
                continue;
            }
            if (g[xn][yn] == '#' or d[xn][yn] < INF) {
                continue;
            }
            d[xn][yn] = d[u.x][u.y] + 1;
            q.push({xn, yn});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    grid g(n);
    for (int i = 0; i < m; ++i) {
        cin >> g[i];
    }
    cord start;
    cin >> start.x >> start.y;
    --start.x;
    --start.y;
    vector<vector<int>> d(n, vector<int>(m, INF));
    bfs(g, start, d);
    for (const vector<int>& row : d) {
        for (int elem : row) {
            cout << (elem == INF ? -1 : elem) << ' ';
        }
        cout << endl;
    }
}