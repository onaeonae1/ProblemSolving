#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
int N, M, K;
int burgers[105];
int fries[105];
int DP[105][305][305];
int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &burgers[i], &fries[i]);
	}
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		int currentBurger = burgers[i];
		int currentFry = fries[i];
		for (int j = M; j >= 0; j--) {
			for (int k = K; k >= 0; k--) {
				bool burgerOK = ((j - currentBurger) >= 0);
				bool fryOK = ((k - currentFry) >= 0);
				if (burgerOK && fryOK) {
					int now = DP[i - 1][j][k];
					int next = DP[i - 1][j - currentBurger][k - currentFry] + 1;
					DP[i][j][k] = (now < next) ? next : now;
				}
				else {
					DP[i][j][k] = DP[i - 1][j][k];
				}

				ret = (ret < DP[i][j][k]) ? DP[i][j][k] : ret;
			}
		}
	}
	printf("%d", ret);
	return  0;
}
