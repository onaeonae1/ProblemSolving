#include<iostream>
#include<deque>
using namespace std;
int N, T;
int arr[400005];
int L = 400005;
int do_search() {
	deque<int> dq; // 이제부터 방문은 여기서부터 관리한다
	// 0 1 BFS -> 0 은 앞으로, 1은 뒤로 
	// 무조건 앞에서 뽑는다
	int ans = 1e9;
	arr[N] = 0;
	dq.push_back(N);
	while (!dq.empty()) {
		int nowPos = dq.front();
		int nowCost = arr[nowPos];

		if (nowPos == T) {
			ans = arr[nowPos];
			break;
		}
		dq.pop_front();
		// 순간 이동을 커버한다
		int tempPos = nowPos;
		while (tempPos <=T *2 && tempPos!=0) {
			if (arr[tempPos] > nowCost) { // 방문할 가치가 있다
				arr[tempPos] = nowCost;
				dq.push_front(tempPos);
			}
			tempPos *= 2;
		}
		int beforeNow = nowPos - 1;
		int afterNow = nowPos + 1;
		if (beforeNow >= 0 && beforeNow < L) {
			int beforeCost = arr[beforeNow];
			if ((nowCost + 1) < beforeCost) {
				arr[beforeNow] = nowCost+ 1;
				dq.push_back(beforeNow);
			}
		}
		if (afterNow >= 0 && afterNow < L) {
			int afterCost = arr[afterNow];
			if ((nowCost + 1)< afterCost) {
				arr[afterNow] = nowCost + 1;
				dq.push_back(afterNow);
			}
		}
	}
	return ans;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> T;
	for (int i = 0; i < 400000; i++) {
		arr[i] = 1e9;
	}
	int ans = do_search();
	cout << ans << "\n";
	return 0;
}
