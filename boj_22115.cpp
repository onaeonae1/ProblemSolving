#include<iostream>
#include<cstring>
using namespace std;
int N, K;
int values[100005];
int dp[105][100005];
int LIMIT = 99999999;
int BLANK = -1;
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &values[i]);
	}
	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= N; i++) {
		int currentValue = values[i];
		for (int j = 0; j < currentValue; j++) {
			// 기존의 최적 값을 일단은 복사합시다
			if (dp[i - 1][j] != BLANK) {
				dp[i][j] = dp[i - 1][j];
			}
		}
		for (int j = currentValue; j <= K; j++) {
			// 기존에 좋은 값이 있으시다는데 복사하자
			int ret = LIMIT;
			if (dp[i - 1][j] != BLANK) {
				ret = dp[i - 1][j];
			}
			if (dp[i - 1][j - currentValue] != BLANK) {
				int next = dp[i - 1][j - currentValue] + 1;
				ret = (ret < next) ? ret : next;
			}
			if (ret != LIMIT) {
				dp[i][j] = ret;
			}
		}
		dp[i][currentValue] = 1;
	}
	int res = dp[N][K];
	if (K == 0) {
		res = 0;
	}
	printf("%d", res);
	return 0;
}
