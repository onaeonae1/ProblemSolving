#include <iostream>
#include <queue>
using namespace std;

int N;
int board[105][105];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
bool visited[105][105];

bool checkRange(int y, int x) {
    return (0 <= y && y < N && 0 <= x && x < N);
}

int bfs(int y, int x, int p) {
    queue<pair<int, int>> nextPoints;
    nextPoints.push({y, x});
    visited[y][x] = true; // 방문 처리

    while (!nextPoints.empty()) {
        pair<int, int> item = nextPoints.front();
        nextPoints.pop();
        int nowY = item.first;
        int nowX = item.second;

        // 인접한 네 방향 탐색
        for (int i = 0; i < 4; i++) {
            int ny = nowY + dy[i];
            int nx = nowX + dx[i];
            if (checkRange(ny, nx) && !visited[ny][nx] && board[ny][nx] == p) {
                visited[ny][nx] = true;
                nextPoints.push({ny, nx});
            }
        }
    }
    return 1; 
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char temp;
            cin >> temp;
            if (temp == 'R') board[i][j] = 3;
            else if (temp == 'G') board[i][j] = 2;
            else if (temp == 'B') board[i][j] = 1;
        }
    }

    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                ans1 += bfs(i, j, board[i][j]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
            if (board[i][j] == 3) board[i][j] = 2; // R을 G로 통합
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                ans2 += bfs(i, j, board[i][j]);
            }
        }
    }

    cout << ans1 << " " << ans2 << "\n";
    return 0;
}
