#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int INF = 1e9;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool inRange(int ny, int nx) {
    return ny >= 0 && ny < n && nx >= 0 && nx < m;
}

struct Node {
    int cost_a, cost_b, y, x;
    bool operator>(const Node& other) const {
        if (cost_a != other.cost_a) return cost_a > other.cost_a;
        return cost_b > other.cost_b;
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    vector<string> board(n);
    pair<int, int> start;
    pair<int, int> flower;

    for (int i = 0; i < n; ++i) {
        cin >> board[i];
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 'S') start = { i, j };
            if (board[i][j] == 'F') flower = { i, j };
        }
    }
    vector<vector<int>> trash(n, vector<int>(m, 0));
    vector<vector<int>> trash_adj(n, vector<int>(m, 0));
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            if (board[y][x] == 'g') {
                trash[y][x] = 1;
            }
            else if (board[y][x] == '.') {
                for (int k = 0; k < 4; ++k) {
                    int ny = y + dy[k];
                    int nx = x + dx[k];
                    if (inRange(ny, nx) && board[ny][nx] == 'g') {
                        trash_adj[y][x] = 1;  
                        break;
                    }
                }
            }
        }
    }

    vector<vector<pair<int, int>>> dist(n, vector<pair<int, int>>(m, { INF, INF }));
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    pq.push({ 0, 0, start.first, start.second });
    dist[start.first][start.second] = { 0, 0 };

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int cur_a = current.cost_a;
        int cur_b = current.cost_b;
        int y = current.y;
        int x = current.x;
        if (make_pair(cur_a, cur_b) > dist[y][x]) {
            continue; 
        }

        for (int k = 0; k < 4; ++k) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (!inRange(ny, nx)) { 
                continue; 
            }

            int next_a = cur_a + trash[ny][nx];
            int next_b = cur_b + trash_adj[ny][nx];

            // 더 좋은 경로라면 갱신
            if (make_pair(next_a, next_b ) < dist[ny][nx]) {
                dist[ny][nx] = { next_a, next_b };
                pq.push({ next_a, next_b, ny, nx });
            }
        }
    }

    // 결과 출력
    pair<int, int> result = dist[flower.first][flower.second];
    cout << result.first << " " << result.second << "\n";
    return 0;
}
