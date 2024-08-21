#include<iostream>
using namespace std;
int board[1005][1005];
int DP[1005][1005][4];
int dx[2];
int dy[2];
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	// 0->1 , 1->2, 2->0
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				// dltoRlsms Ekfrldndbqnxj tlwkrgksms rotoRlek
				DP[i][j][0] = 1;
			}
		}
	}

	int ans = 0;
	int variations = 3;
	dy[0] = 0;
	dy[1] = -1;
	dx[0] = -1;
	dx[1] = 0;
	
	

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			for (int t = 0; t < 2; t++) {
				int beforeX = x + dx[t];
				int beforeY = y + dy[t];

				if (beforeX<1 || beforeY <1 || beforeX >N || beforeY >N) {
					// 이새끼들은 그냥 무시한다
					continue;
				}
				
				int now = board[y][x];
				int exp = (board[y][x] + variations - 1) % variations;
				for (int t = 0; t < variations; t++) {
					// 아 모르겠고 그냥 일단 덮어씀
					DP[y][x][t] = (DP[y][x][t] < DP[beforeY][beforeX][t]) ? DP[beforeY][beforeX][t] : DP[y][x][t];
				}

				if (DP[beforeY][beforeX][exp] > 0) {
					// 앞자리에서 잡수신게 있네
					DP[y][x][now] = (DP[y][x][now] < DP[beforeY][beforeX][exp] + 1) ? DP[beforeY][beforeX][exp] + 1 : DP[y][x][now];
				}

			}
		}
	}
	
	for (int t = 0; t < variations; t++) {
		ans = (ans < DP[N][N][t]) ? DP[N][N][t] : ans;
	}
	cout << ans << endl;

	return 0;
}
