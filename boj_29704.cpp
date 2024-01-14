#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
int N, T;
int costs[1005];
int values[1005];
int DP[1005];
int sum = 0;
int main() {
	scanf("%d %d", &N, &T);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &costs[i], &values[i]);
		sum += values[i];
	}
	for (int i = 1; i <= N; i++) {
		int currentCost = costs[i];
		int currentValue = values[i];
		for (int j = T; j >= 0; j--) {
			if (j - currentCost >= 0) {
				int now = DP[j];
				int next = DP[j - currentCost] + currentValue;
				DP[j] = (now < next) ? next : now;
			}
		}
	}
	printf("%d", sum-DP[T]);
	return 0;
}
