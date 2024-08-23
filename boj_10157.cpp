#include<iostream>
using namespace std;
int board[1005][1005];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int W, H;
	int target;
	int current = 0;
	cin >> W >> H;
	cin >> target;
	int y = 1;
	int x = 1;
	
	board[y][x] = 1;
	if (target > W * H) {
		cout << 0 << endl;
		return 0;
	}

	int cnt = 2;
	while (cnt <= target) {
		if (board[y][x] == target) {
			break;
		}

		int nx = x + dx[current % 4];
		int ny = y + dy[current % 4];

		if (ny <= H && ny >= 1 && nx <= W && nx >= 1 && board[ny][nx] == 0) {
			// good to go
			board[ny][nx] = cnt;
			x = nx;
			y = ny;
			cnt++;
		}
		else {
			current++;
		}
	}

	cout << x << " " << y << endl;
	return 0;
}
