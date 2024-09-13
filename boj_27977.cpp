#include <iostream>
using namespace std;
int items[100005];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int L, N, K;
	int gap = 0;
	cin >> L >> N >> K;
	items[0] = 0;
	items[N + 1] = L;
	for (int i = 1; i <= N; i++) {
		cin >> items[i];
		int t = items[i] - items[i - 1];
		gap = (gap < t) ? t : gap;
		
	}
	gap = (gap < items[N + 1] - items[N]) ? items[N + 1] - items[N] : gap;

	int ans = L;
	int start = gap;
	int end = L;
	while (start <= end) {
		int mid = (start + end) / 2;
		int chargeCnt = 0;
		int edge = 0;
		for (int i = 1; i <= N + 1; i++) {
			if (items[i] - edge > mid) {
				chargeCnt++;
				if (items[i] - edge == mid) { 
					edge = items[i]; 
				}
				else {
					edge = items[i - 1];
				}
			}
		}
		if (chargeCnt > K) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
			ans = min(ans, mid);
		}
	}
	cout << ans;
}
