#include<iostream>
using namespace std;
int N, M, K;
int values[500];
int DP[500][500];
int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &values[i]);
		int modValue = values[i] % K;
		// 하나 선택시의 최대 값
		int now = DP[1][modValue];
		int next = values[i];
		DP[1][modValue] = (now < next) ? next : now;
	}
	// 선택한 친구들의 개수
	for (int i = 2; i <= M; i++) {
		// 대상이 되는 놈을 확인
		for (int j = 1; j <= N; j++) {
			// 나머지값들
			int value = values[j];
			for (int k = 0; k < K; k++) {
				int diff = (k - value) % K;
				int idx = (diff < 0) ? diff + K : diff;
				if (DP[i-1][idx] != 0) {
					int now = DP[i][k];
					int next = DP[i - 1][idx] + value;
					DP[i][k] = (now < next) ? next : now;
					// printf("DP[%d][%d] updated ->  %d from now : %d , next: %d\n", i, k, DP[i][k], now, next);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= M; i++) {
		ans = (ans <= DP[i][0]) ? DP[i][0] : ans;
	}
	printf("%d", ans);
	return 0;
}
