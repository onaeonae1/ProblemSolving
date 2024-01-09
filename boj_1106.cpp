#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int C, N;

// 중복을 허용한다
int DP[100005];
int costs[1005];
int values[1005];
int main() {
	scanf("%d %d", &C, &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &costs[i], &values[i]);
	}
	for (int i = 1; i <= N; i++) {
		int currentValue = values[i];
		int currentCost = costs[i];
		// j는 비용들의 합이 될 것임
		for (int j = currentCost; j <= 1000 * 100; j++) {
			int now = DP[j];
			int next = DP[j - currentCost] + currentValue;
			DP[j] = (now < next) ? next : now;
		}
	}
	int ans = 0;
	for (int i = 0; i <= 1000 * 100; i++) {
		if (DP[i] >= C) {
			ans = i;
			break;
		}
	}
	printf("%d", ans);
}
