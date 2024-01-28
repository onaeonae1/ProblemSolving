#include<iostream>
#define lld long long int
using namespace std;
lld B[200005];
int main() {
	lld N, K;
	lld maxB = -(20 * 20 * 10000 * 10000 + 1);
	lld ans = 0;
	scanf("%lld %lld", &N, &K);
	for (int i = 0; i < N; i++) {
		lld temp;
		scanf("%lld", &temp);
		if (i == 0) {
			B[i] = temp;
		}
		else {
			B[i] = temp - (i * K);
		}
		maxB = (maxB < B[i]) ? B[i] : maxB;
	}
	
	for (int i = 0; i < N; i++) {
		ans += (maxB - B[i]);
	}
	printf("%lld", ans);
	return 0;
}
