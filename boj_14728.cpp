#include<iostream>
using namespace std;
int N, M;
int costs[105];
int values[105];
int DP[105][10005];
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &costs[i], &values[i]);
	}
	for (int i = 1; i <= N; i++) {
		int currentCost = costs[i];
		int currentValue = values[i];
		for (int j = 0; j <= M; j++) {
			if (j - currentCost >= 0) {
				int now = DP[i - 1][j];
				int next = DP[i - 1][j - currentCost] + currentValue;
				DP[i][j] = (now < next) ? next : now;
			}
			else {
				DP[i][j] = DP[i - 1][j];
			}
		}
	}
	printf("%d", DP[N][M]);
  return 0;
}
