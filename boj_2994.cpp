#include<iostream>
using namespace std;
int T, N;
int DP[5][10005];
int visited[5][10005];
int costs[10005];
int ans[10005]; 
int main() {
	scanf("%d %d", &T, &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &costs[i]);
	}
	int ret;
	// 사람 수 만큼
	for (int i = 1; i <= N; i++) {
		ret = 0;
		int currentCost = costs[i];
		// 배낭 수 
		for (int j = 1; j <= 2; j++) {
			if (visited[j][i] != 0) {
				visited[j][i] = 0;
				DP[j][i] = DP[j][i - 1];
			}
			else {
				if (ret == 0 && DP[j][i-1] + currentCost <= T) {
					DP[j][i] = DP[j][i - 1] + currentCost;
					visited[j][i] = 1;
					ret++;
				}
				else {
					DP[j][i] = DP[j][i - 1];
				}
			}
		}
		if (ret == 0) {
			i -= 2;
		}
	}

	//tracking
	
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i][j] == 1) {
				ans[j] = DP[i][j - 1];
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		printf("%d ", ans[i]);
	}
	
	return 0;
}
