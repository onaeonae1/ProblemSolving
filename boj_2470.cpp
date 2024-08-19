#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long int INF = 1e18;
int main() {
	int N;
	scanf("%d", &N);
	vector<long long int> items(N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &items[i]);
	}
	sort(items.begin(), items.end());
	int left = 0;
	int right = N-1;
	long long int ans = INF;
	pair<long long int, long long int> ret;
	while (left < right) {
		long long mix = items[right] + items[left];
		if (abs(mix) < ans) {
			ans = abs(mix);
			ret.first = items[left];
			ret.second = items[right];
		}
		if (mix < 0) {
			// 왼쪽이 더 크다
			left++;
		}
		else {
			// 오른쪽이 더 크다
			right--;
		}
	}
	// printf("%lld", ans);
	printf("%lld %lld", ret.first, ret.second);
    return 0;
}
