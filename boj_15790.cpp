#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, M, K;
vector<int> items;
bool do_search(int t) {
	bool isValid = false;
	// t의 GAP을 가진 채 K개의 item을 만들 수 있는가
	for (int i = 0; i < M; i++) {
		//i is start 
		int now = items[i];
		int sliced = 1;
		int nextIdx = (i + 1) % M;
		int left = N;
		while (true) {
			if (sliced == K) {
				if (left >= t) {
					// 다 찾았다
					isValid = true;
					return isValid;
				}
				break;
			}
			if (nextIdx == i) {
				// 한바퀴 돌았음
				break;
			}
			int next = items[nextIdx];
			int gap = (now < next) ? (next - now) : (now + N - next);
			if (gap >= t) {
				now = next;
				sliced++;
				left -= gap;
			}
			nextIdx = (nextIdx + 1) % M;
		}
	}

	return isValid;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int t;
		cin >> t;
		items.push_back(t);
	}
	sort(items.begin(), items.end());

	int start = 0;
	int end = 10005;
	int ans = 0;

	if (K == 1) {
		ans = N;
		cout << ans << "\n";
		return 0;
	}

	while (start <= end) {
		int mid = (start + end) / 2;
		bool isValid = do_search(mid);
		if (isValid) {
			// 이 t로 충분히 자를 수 있다
			ans = (ans < mid) ? mid : ans;
			start = mid + 1;
		}
		else {
			end = mid-1;
		}
	}
	cout << ans << "\n";
	return 0;
}
