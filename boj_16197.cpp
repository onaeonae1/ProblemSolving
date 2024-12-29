#include <iostream>
#include <queue>
#include <tuple> // tuple 사용
#include <vector>
using namespace std;

int N, M;
vector<string> board;
bool visited[21][21][21][21]; // 두 동전의 상태를 저장
int dx[4] = { 0, 0, -1, 1 };    // 왼쪽, 오른쪽, 위, 아래
int dy[4] = { -1, 1, 0, 0 };

struct State {
    int x1, y1, x2, y2, count;
};

bool isOutside(int x, int y) {
    return x < 0 || x >= N || y < 0 || y >= M;
}

int bfs(pair<int, int> coin1, pair<int, int> coin2) {
    queue<State> q;
    q.push({ coin1.first, coin1.second, coin2.first, coin2.second, 0 });
    visited[coin1.first][coin1.second][coin2.first][coin2.second] = true;

    while (!q.empty()) {
        int x1 = q.front().x1;
        int y1 = q.front().y1;
        int x2 = q.front().x2;
        int y2 = q.front().y2;
        int count = q.front().count;
        q.pop();

        // 버튼을 10번 이상 누르면 실패
        if (count >= 10) return -1;

        for (int i = 0; i < 4; i++) {
            int nx1 = x1 + dx[i], ny1 = y1 + dy[i];
            int nx2 = x2 + dx[i], ny2 = y2 + dy[i];

            // 벽에 부딪히면 제자리
            if (!isOutside(nx1, ny1) && board[nx1][ny1] == '#') {
                nx1 = x1;
                ny1 = y1;
            }
            if (!isOutside(nx2, ny2) && board[nx2][ny2] == '#') {
                nx2 = x2;
                ny2 = y2;
            }

            // 동전이 보드 밖으로 떨어졌는지 확인
            bool out1 = isOutside(nx1, ny1);
            bool out2 = isOutside(nx2, ny2);

            if (out1 && out2) continue;       // 둘 다 떨어지면 실패
            if (out1 || out2) return count + 1; // 하나만 떨어지면 성공

            // 이미 방문한 상태라면 건너뜀
            if (!visited[nx1][ny1][nx2][ny2]) {
                visited[nx1][ny1][nx2][ny2] = true;
                q.push({ nx1, ny1, nx2, ny2, count + 1 });
            }
        }
    }

    return -1; // 성공하지 못한 경우
}

int main() {
    cin >> N >> M;
    board.resize(N);
    pair<int, int> coin1, coin2;
    bool firstCoin = true;

    for (int i = 0; i < N; i++) {
        cin >> board[i];
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'o') {
                if (firstCoin) {
                    coin1 = { i, j };
                    firstCoin = false;
                }
                else {
                    coin2 = { i, j };
                }
            }
        }
    }
    cout << bfs(coin1, coin2) << endl;
    return 0;
}
