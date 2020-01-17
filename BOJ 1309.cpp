#include<stdio.h>
long long int DP[100001];
int main() {
	int n;
	scanf("%d", &n);
	DP[0] = 1;
	DP[1] = 3;
	if (n >= 2) {
		for (int i = 2; i <= n; i++) {
			DP[i] = 2 * DP[i - 1] + DP[i - 2];
			DP[i] %= 9901;
		}
	}
	printf("%lld", DP[n]);
	return 0;
}
