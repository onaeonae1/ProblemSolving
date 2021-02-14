#include<iostream>
#define L 505
using namespace std;
int n, m;
int board[L][L];
int dp[L][L]; //dp [i][j] : (i,j)에서 끝까지 가능한 내리막길 경우의 수
int dy[] = { -1, 0, 1, 0, };
int dx[] = { 0, 1, 0, -1 };
int dfs(int y , int x) {
	if (y == n && x == m) { //최종지점 방문
		return 1;
	}
	else if (dp[y][x] == -1) {
		dp[y][x] = 0;
		for (int i = 0; i < 4; i++) {
			int nY = y + dy[i];
			int nX = x + dx[i];
			//범위 체크
			if ((1 <= nY && nY <= n) && (1 <= nX && nX <= m)) {
				//내리막길 체크
				if (board[y][x] > board[nY][nX]) {
					dp[y][x] += dfs(nY, nX);
				}
			}
		}
	}
	return dp[y][x];
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// 배열 입력받고 DP 초기화
			scanf("%d", &board[i][j]);
			dp[i][j] = -1;
		}
	}
	int ans = dfs(1, 1);
	printf("%d\n", ans);
	return 0;
}
