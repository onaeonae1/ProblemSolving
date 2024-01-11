#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int n, m, k;
int parent[30005];
int dp[3010];
int value[30005];
int cost[30005];
int find_root(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = find_root(parent[x]);
}
void u_nion(int x, int y) {
	x = find_root(x);
	y = find_root(y);

	if (x < y) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}
int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &value[i]);
		cost[i] = 1;
	}
	int alpha, beta;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &alpha, &beta);
		u_nion(alpha, beta);
	}

	for (int i = 1; i <= n; i++) {
		// parent 에 맞춘다
		if (parent[i] != i) {
			int p = find_root(i);
			value[p] += value[i];
			cost[p] += cost[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (parent[i] == i) {
			int currentCost = cost[i];
			int currentValue = value[i];
			for (int j = k - 1; j - currentCost >= 0; j--) {
				int now = dp[j];
				int next = dp[j - currentCost] + currentValue;
				dp[j] = (now < next) ? next : now;
			} 
		}
	}
	printf("%d", dp[k - 1]);
	return 0;
}
