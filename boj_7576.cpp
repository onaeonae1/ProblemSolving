#include<iostream>
#include<queue>
#include<string>
using namespace std;
int board[1005][1005];
bool visit[1005][1005];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };
int Y, X;
struct point {
	int y;
	int x;
	int cnt;
};
bool checkRange(int y, int x) {
	bool inY = (0 <= y && y < Y);
	bool inX = (0 <= x && x < X);
	return (inY && inX);
}
bool checkValid(int y, int x) {
	if (checkRange(y, x)) {
		return (!visit[y][x] && (board[y][x] == 0));
	}
	else {
		return false;
	}
}
int bfs() {
	// 최초 확인
	int ans = -1;
	queue<point> alives;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (board[i][j] == 1) {
				alives.push({ i,j,0 });
				visit[i][j] = true;
			}
		}
	}
	while (!alives.empty()) {
		point now = alives.front();
		alives.pop();
		int y = now.y;
		int x = now.x;
		int cnt = now.cnt;
		ans = (ans < cnt) ? cnt : ans;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (checkValid(ny, nx)) {
				alives.push({ ny, nx, cnt + 1 });
				board[ny][nx] = 1;
			}
		}
	}
	bool hasZero = false;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (board[i][j] == 0) {
				hasZero = true;
				break;
			}
		}
	}
	ans = (hasZero) ? -1 : ans;
	return ans;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> X >> Y; 
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			cin >> board[i][j];
		}
	}
	cout << bfs() << "\n";
	return 0;
}
