#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int T, E, V;
vector<pair<int, int>> board[105];
int dist[105];
int visit[105];
const int INF = 1e9;

int dij(int start, int to, int t) {
    fill_n(dist, 105, INF);
    fill_n(visit, 105, -1);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> jobq;
    jobq.push({0, start});

    while (!jobq.empty()) {
        pair<int, int> now = jobq.top();
        jobq.pop();

        int currentCost = now.first;
        int currentNode = now.second;

        if (currentCost > dist[currentNode]) continue;

        for (auto next : board[currentNode]) {
            int nextNode = next.second;
            int nextCost = next.first + currentCost;

            if (nextCost < dist[nextNode]) {
                dist[nextNode] = nextCost;
                visit[nextNode] = currentNode;
                jobq.push({nextCost, nextNode});
            }
        }
    }

    if (dist[to] >= INF) {
        cout << "Case #" << t << ": " << -1 << "\n";
        return -1;
    }

    vector<int> ret;
    while (to != -1) {
        ret.push_back(to);
        to = visit[to];
    }

    cout << "Case #" << t<<":"<<" ";
    for (int i = ret.size() - 1; i >= 0; --i) {
        cout << ret[i] << (i == 0 ? "\n" : " ");
    }

    return dist[ret[0]];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> E >> V;
        for (int i = 0; i < E; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            board[from].push_back({cost, to});
            board[to].push_back({cost, from});
        }

        dij(0, V - 1, t);

        // Clear board
        for (int i = 0; i < 105; i++) {
            board[i].clear();
        }
    }

    return 0;
}
