#include<iostream>
#include<queue>
int board[605][605];
bool visited[605][605];
int Y, X;
using namespace std;
int dy[] = { -1,1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };
bool checkInRange(int y, int x) {
	bool inRange = (1 <= y && y <= Y) && (1 <= x && x <= X);
	return inRange;
}
bool checkValid(int y, int x) {
	bool inRange = checkInRange(y, x);
	bool notVisit = !visited[y][x];
	bool notWall = board[y][x] != 0;
	return (inRange && notVisit && notWall);

}
int bfs(int sty, int stx) {
	int cnt = 0;
	queue<pair<int, int>> jobq;
	jobq.push({ sty, stx });
	visited[sty][stx] = true;
	while (!jobq.empty()) {
		pair<int, int> now = jobq.front();
		jobq.pop();
		int nowY = now.first;
		int nowX = now.second;
		if (!checkInRange(nowY, nowX)) {
			continue;
		}
		if (board[nowY][nowX] == 1) {
			cnt++;
		}
		for (int i = 0; i < 4; i++) {
			int ny = nowY + dy[i];
			int nx = nowX + dx[i];
			if (checkValid(ny, nx)) {
				jobq.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}
	}
	return cnt;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> Y >> X;
	int sty, stx;
	for (int i = 1; i <= Y; i++) {
		for (int j = 1; j <= X; j++) {
			char c;
			cin >> c;
			if (c == 'O') {
				board[i][j] = 2;
			}
			else if (c == 'P') {
				board[i][j] = 1;
			}
			else if (c == 'I') {
				board[i][j] = 3;
				sty = i;
				stx = j;
			}
		}
	}
	int ret = bfs(sty, stx);
	if (ret == 0) {
		cout << "TT"<<"\n";
	}
	else {
		cout << ret << "\n";
	}
	return 0;
}
