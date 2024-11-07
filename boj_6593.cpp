#include<iostream>
#include<string>
#include<queue>
using namespace std;
int Z, Y, X;
int visited[35][35][35];
int board[35][35][35]; // 기본값은 0 은 벽이다
int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };
struct pt {
	int z;
	int y;
	int x;
};
void clear() {
	for (int i = 0; i < 35; i++) {
		for (int j = 0; j < 35; j++) {
			for (int k = 0; k < 35; k++) {
				board[i][j][k] = 0;
				visited[i][j][k] = 0;
			}
		}
	}
}
bool checkInRange(int z, int y, int x) {
	bool zRange = (0 <= z) && (z < Z);
	bool xRange = (0 <= x) && (x < X);
	bool yRange = (0 <= y) && (y < Y);
	return (zRange && yRange && xRange);
}
bool checkValid(int z, int y, int x) {
	if (!checkInRange(z, y, x)) {
		return false;
	}
	bool isNotWall = (board[z][y][x] != 0);
	bool isNotVisited = !(visited[z][y][x] == 1);

	return (isNotVisited && isNotWall);
}
void bfs(pt start, pt end) {
	int ans = 1e9;
	queue<pair<pt, int>> jobq;
	jobq.push({ start, 0 });
	visited[start.z][start.y][start.x] = 1;
	bool isExit = false;

	int edz = end.z;
	int edy = end.y;
	int edx = end.x;

	while (!jobq.empty()) {
		pair<pt, int> now = jobq.front();
		jobq.pop();
		pt pos = now.first;
		int cnt = now.second;
		int z = pos.z;
		int y = pos.y;
		int x = pos.x;

		if (z == edz && y == edy && edx == x) {
			ans = (ans > cnt) ? cnt : ans;
			break;
		}
		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (checkValid(nz, ny, nx)) {
				jobq.push({{nz,ny,nx}, cnt + 1});
				visited[nz][ny][nx] = 1;
			}
		}
	}

	if(ans==1e9){
		cout << "Trapped!" << "\n";
	}
	else {
		cout << "Escaped in " << ans << " minute(s)." << "\n";
	}
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	while (true) {
		cin >> Z >> Y >> X;
		if (!Z && !Y && !X) {
			break;
		}
		pt stp, edp;
		for (int z = 0; z < Z; z++) {
			for (int y = 0; y < Y; y++) {
				for (int x = 0; x < X; x++) {
					char c;
					cin >> c;
					if (c == 'S') {
						board[z][y][x] = 1;
						stp.z = z;
						stp.y = y;
						stp.x = x;
					}
					else if (c == '.') {
						board[z][y][x] = 1;
					}
					else if (c == 'E') {
						board[z][y][x] = 1; 
						edp.z = z;
						edp.y = y;
						edp.x = x;
					}
				}
			}
		}
		bfs(stp, edp);
		clear();
	}
	return 0;
}
