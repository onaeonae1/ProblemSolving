#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, K;
vector<int> points;
vector<int> specs; // 실제로 관심이 있는 파트
bool do_spec_search(int t) {
	bool isValid = false;
	int now = specs.back();
	int cnt = 0;
	while (now > 0 && now <= N - 1 && cnt < K) {
		int next = max(now - t, 0);
		int pos = lower_bound(specs.begin(), specs.end(), next) - specs.begin();
		now = specs[pos];
		cnt++;
	}
	isValid = (now == 0) && (cnt <= K);
	return isValid;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		points.push_back(t);
		if (t == 1 || i==0) {
			specs.push_back(i);
		}
	}
	int start = 0;
	int end = 200005;
	int ret = 200005;
	while (start <= end) {
		int mid = (start + end) / 2;
		bool isValid = do_spec_search(mid);
		if (isValid) {
			end = mid - 1;
			ret = mid;
		}
		else {
			start = mid + 1;
		}
	}
	cout << ret << "\n";
	return 0;
}
