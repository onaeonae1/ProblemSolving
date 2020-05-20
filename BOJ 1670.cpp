#include<iostream>
#define L 10005
#define MOD 987654321
using namespace std;
long long int DP[L];
int main() {
	DP[0] = 1;
	DP[2] = 1;
	int n;
	scanf("%d", &n);
	for (int num = 4; num <= n; num += 2) {
		int k = num / 2;
		long long int count = 0;
		for (int i = 0; i <= num - 2; i+=2) { // (a, b c) 로 분할하는데 b는 2로 고정이다.
			count += (DP[i] * DP[num - 2 - i]);
			count %= MOD;
		}
		DP[num] = count;
	}
	printf("%lld", DP[n]);
	return 0;
}
