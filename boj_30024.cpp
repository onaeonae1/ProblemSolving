#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int board[1005][1005];
struct point {
    int value;
    int y;
    int x;
    bool operator <(const point& a) const {
        return value < a.value;
    }
};
priority_queue<point, vector<point>> pq;
vector<pair<int, int>> paths;
int dy[] = { 1,-1, 0, 0 };
int dx[] = { 0,0,1,-1 };
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
            if (i == 1 || j == 1 || i == N || j == M) {
                pq.push({ board[i][j], i, j });
            }
        }
    }
    cin >> K;
    int cnt = 0;
    while (cnt < K && !pq.empty()) {
        point current = pq.top();
        int cy = current.y;
        int cx = current.x;
        int cv = current.value;
        pq.pop();
        if (board[cy][cx] == 0) {
            continue;
        }
        board[cy][cx] = 0; // 방문 처리
        cnt++;
        paths.push_back({ cy,cx });

        // 4방향 탐색
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 1 && ny <= N && nx >= 1 && nx <= M) {
                if (board[ny][nx] != 0) {
                    pq.push({ board[ny][nx], ny, nx });
                }
            }
        }
    }
    for (int i = 0; i < paths.size(); i++) {
        cout << paths[i].first << " " << paths[i].second << "\n";
    }

    return 0;
}
