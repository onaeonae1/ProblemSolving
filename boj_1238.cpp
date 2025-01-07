#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> adj[1005]; // {cost, to}
int dist[1005];
int N, M, X;
const int INF = 1e9;
int dij(int start, int end) {
    fill_n(dist, 1005, INF); // 배열 초기화
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> jobq; // 최소힙
    jobq.push({ 0, start }); // {cost, node}

    while (!jobq.empty()) {
        pair<int, int> now = jobq.top();
        jobq.pop();

        int nowCost = now.first;
        int nowNode = now.second;

        if (nowCost > dist[nowNode]) {
            continue;
        }
        for (auto next : adj[nowNode]) {
            int nextCost = next.first;
            int nextNode = next.second;

            if (dist[nextNode] > nowCost + nextCost) { // 최단 거리 갱신
                dist[nextNode] = nowCost + nextCost;
                jobq.push({ dist[nextNode], nextNode });
            }
        }
    }
    return dist[end];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        int from, to, value;
        cin >> from >> to >> value;
        adj[from].push_back({ value, to });
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int t1 = dij(i, X); 
        int t2 = dij(X, i); 
        if (t1 < INF && t2 < INF) {
            ans = max(ans, t1 + t2);
        }
    }
    cout << ans << "\n";
}
