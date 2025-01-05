#include<iostream>
#include<queue>
using namespace std;
int Y, X;
int board[2][305][305];
bool isVisit[2][305][305];
int dx[] = { 1,-1, 0, 0 };
int dy[] = { 0,0,-1,1 };
int P;
bool inRange(int y, int x) {
	bool validY = (y >= 0 && y < Y);
	bool validX = (x >= 0 && x < X);
	return validY && validX;
}
void meltdown(int p) {
	int nextP = (p + 1) % 2;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			int cnt = board[p][i][j];
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (inRange(ny, nx)) {
					if (board[p][ny][nx] == 0) {
						cnt--;
					}
				}
			}
			cnt = (cnt >= 0) ? cnt : 0;
			board[nextP][i][j] = cnt;
		}
	}
}
int checkIceGroup(int p) {
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			isVisit[p][i][j] = false;
		}
	}

	int chunks = 0;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (board[p][i][j] != 0 && !isVisit[p][i][j]) {
				chunks++;
				queue<pair<int, int>> q;
				q.push({ i, j });
				isVisit[p][i][j] = true;

				while (!q.empty()) {
					pair<int, int> now = q.front();
					int cy = now.first;
					int cx = now.second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int ny = cy + dy[k];
						int nx = cx + dx[k];
						if (inRange(ny, nx) && !isVisit[p][ny][nx] && board[p][ny][nx] != 0) {
							isVisit[p][ny][nx] = true;
							q.push({ ny, nx });
						}
					}
				}
			}
		}
	}
	return chunks;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> Y >> X;
	bool hasIce = false;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			cin >> board[P][i][j];
			if (board[P][i][j] != 0) {
				hasIce = true;
			}
		}
	}
	if (!hasIce) {
		cout << 0 << "\n";
		return 0;
	}

	int year = 0;
	while (true) {
		meltdown(P);
		int nextP = (P + 1) % 2;
		year++;
		int chunks = checkIceGroup(nextP);
		if (chunks >= 2) {
			break;
		}
		if (chunks == 0) {
			year = 0;
			break;
		}
		P = nextP;
	}
	
	cout << year << "\n";
	return 0;
}
