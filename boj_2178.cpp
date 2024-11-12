#include<iostream>
#include<queue>
#include<string>
using namespace std;
int board[105][105];
bool visit[105][105];
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
		return (!visit[y][x] && (board[y][x] != 0));
	}
	else {
		return false;
	}
}
int bfs() {
	int ans = 1;
	int sty = 0;
	int stx = 0;
	queue<point> jobq;
	jobq.push({ sty, stx, 1 });
	visit[sty][stx] = true;
	while (!jobq.empty()) {
		point now = jobq.front();
		jobq.pop();
		int y = now.y;
		int x = now.x;
		int cnt = now.cnt;
		if (y == Y - 1 && x == X - 1) {
			ans = cnt;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (checkValid(ny, nx)) {
				jobq.push({ ny, nx, cnt + 1 });
				visit[ny][nx] = true;
			}
		}
	}
	return ans;
	
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> Y >> X;
	for (int i = 0; i < Y; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < X; j++) {
			char t = s.at(j);
			if (t == '1') {
				board[i][j] = 1;
			}
			else {
				board[i][j] = 0;
			}	
		}
	}
	cout << bfs() << "\n";
	return 0;
}
