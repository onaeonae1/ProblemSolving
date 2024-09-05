#include<iostream>
using namespace std;
int N, M;
int board[1005][1005];
int DP[1005][1005][3]; // /:0 |:1 \:2

bool goodtogo(int tx) {
	bool isValid = false;
	isValid = (tx >= 0 && tx < M);
	return isValid;
}
int get_min(int a, int b) {
	int ret = (a < b) ? a : b;
	return ret;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			for (int k = 0; k < 3; k++) {
				DP[i][j][k] = (i == 0) ? board[i][j] : 1e9;
			}
		}
	}
	// DP[i][j][k] : i,j 에 K 방향으로 오는 최소값
	// k로 오면 DPbefore = k 가 아닌거에서 획득

	// 1번지부터 시작
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			// 왼쪽아래로 간다 (=오른쪽 위에서 온다)
			if (goodtogo(j+1)) {
				DP[i][j][0] = get_min(DP[i - 1][j + 1][1], DP[i - 1][j + 1][2]) + board[i][j];
			}

			// 그냥 수직 범위 고려 필요없음
			DP[i][j][1] = get_min(DP[i - 1][j][0], DP[i - 1][j][2]) + board[i][j];
			
			// 오른쪽 아래로 간다 (= 왼쪽 위에서 온다)
			if (goodtogo(j - 1)) {
				DP[i][j][2] = get_min(DP[i - 1][j - 1][0], DP[i - 1][j - 1][1]) + board[i][j];
			}
		}
	}

	int ans = 1e9;
	for (int x = 0; x < M; x++) {
		for (int k = 0; k < 3; k++) {
			ans = get_min(ans, DP[N - 1][x][k]);
		}
	}
	cout << ans << "\n";
	return 0;
}
