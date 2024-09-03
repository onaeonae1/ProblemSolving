#include<iostream>
#include<queue>
using namespace std;
int N, M;
int board[1005][1005];
int visited[1005][1005][2];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int ans = 1e9;
int nowy;
int nowx;
int depth;
bool isValid(int nextY, int nextX){
	return ((nextY < N && nextY >= 0) && (nextX < M && nextX >= 0));
}
struct point {
	int y;
	int x;
	int wallbreak;
};
void bfs() {
	queue<point> q;
	q.push({ 0, 0, 0 });
	visited[0][0][0] = 1;
	while (!q.empty()) {
		point p = q.front();
		int currentY = p.y;
		int currentX = p.x;
		int isBreak = p.wallbreak;
		// 이미 도착했냐? 
		if (currentY == N - 1 && currentX == M - 1) {
			return;
		}

		q.pop();
		// 4방향 탐색
		for (int i = 0; i < 4; i++) {
			int nextY = currentY + dy[i];
			int nextX = currentX + dx[i];
			bool goodtoGo = isValid(nextY, nextX);
			if (goodtoGo) {
				if (visited[nextY][nextX][isBreak] == 0) {
					if (isBreak == 1) {
						// 앞으로는 무조건 Q 에 break 1 로 넣어야 함
						if (board[nextY][nextX] == 0) {
							q.push({ nextY, nextX, 1 });
							visited[nextY][nextX][1] = visited[currentY][currentX][1] + 1;
						}
					}
					else {
						if (board[nextY][nextX] == 0) {
							q.push({ nextY, nextX, 0 });
							visited[nextY][nextX][0] = visited[currentY][currentX][0] + 1;
						}
						else {
							q.push({ nextY, nextX, 1 });
							visited[nextY][nextX][1] = visited[currentY][currentX][0] +1;
						}
					}
				}
			}
		}

	}
	return;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char s;
			cin >> s;
			board[i][j] = int(s - '0');
		}
	}
	bfs();
	int t1 = (visited[N - 1][M - 1][0] == 0) ? 1e9 : visited[N - 1][M - 1][0];
	int t2 = (visited[N - 1][M - 1][1] == 0) ? 1e9 : visited[N - 1][M - 1][1];
	int ans = (t1 <= t2) ? t1 : t2;
	ans = (ans == 1e9) ? -1 : ans;
	cout << ans << "\n";
	return 0;
}
