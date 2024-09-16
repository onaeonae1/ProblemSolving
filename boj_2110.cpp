#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> items;
int do_search(int t) {
	bool isValid = false;
	int installed = 1;
	int current = items[0];
	for (int i = 1; i <= N-1; i++) {
		int gap = items[i] - current;
		if (gap >= t) {
			current = items[i];
			installed++;
		}
		if (installed >= M) {
			isValid = true;
			break;
		}
	}

	return isValid;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> M; // N -> 집 수/ M -> 공유기의 수
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		items.push_back(t);
	}
	sort(items.begin(), items.end());
	int start = 0;
	int end = 1e9;
	int ans = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		bool isValid  = do_search(mid);
		if (isValid) {
			ans = (ans < mid) ? mid : ans;
			// 이 거리로 가능하다 더 늘여봐
			start = mid + 1;
		}
		else {
			// 이 거리로는 설치 안된다 줄여라
			end = mid-1;
		}
	}
	cout << ans << "\n";
	return 0;
}
