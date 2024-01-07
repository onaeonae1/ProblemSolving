#include<iostream>
using namespace std;
int N, K;
int costs[1005];
int values[1005];
int DP[1005][10005];
int main() {
	scanf("%d %d", &N, &K);
	int ret = 0;
	for (int i = 1; i <= K; i++) {
		scanf("%d %d", &values[i], &costs[i]);
	}
	for (int i = 1; i <= K; i++) {
		int currentCost = costs[i];
		int currentValue = values[i];
		for (int j = 1; j <= N; j++) {
			if (j - currentCost >= 0) {
				int now = DP[i - 1][j];
				int next = DP[i - 1][j - currentCost] + currentValue;
				DP[i][j] = (now < next) ? next : now;
				ret = (DP[i][j] < ret) ? ret : DP[i][j];
			}
			else {
				DP[i][j] = DP[i - 1][j];
			}
		}
	}
	printf("%d", ret);
	return 0;
}
