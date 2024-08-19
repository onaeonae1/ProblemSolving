#include<iostream>
#include<vector>
#define int long long
using namespace std;
signed main() {
	int N, M;
	scanf("%lld %lld", &N, &M);
	vector<int> speeds(N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &speeds[i]);
	}
	int ans = 1e18;
	int tMin = 0;
	int tMax = ans;	
	while (tMin <= tMax) {
		int t = (tMin + tMax) / 2;
		int sum = 0;
		bool isPossible = false;
		for (int i = 0; i < N; i++) {
			sum += (t / speeds[i]);
			if (sum >= M) {
				isPossible = true;
				break;
			}
		}
		if (isPossible) {
			// 아무튼 만족했음
			tMax = t-1;
			ans = (t <= ans) ? t : ans;
		}
		else {
			tMin = t + 1;
		}
	}
	printf("%lld", ans);
	return 0;
}
