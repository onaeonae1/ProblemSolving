#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<vector<int>> graph(10005);
vector<bool> visited(10005, false);

void dfs(int v) {
    visited[v] = true;
    cout << v << " ";
    for (int i : graph[v]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int i : graph[v]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int N, M, V;
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(V);
    cout << "\n";

    fill(visited.begin(), visited.end(), false);

    bfs(V);
    cout << "\n";

    return 0;
}
