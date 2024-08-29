#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<int> t;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < M; i++) {
		pq.push(0);
	}

	for (int i = 0; i < N; i++) {
		int e;
		cin >> e;
		t.push_back(e);
	}
	sort(t.begin(), t.end());
	for (int i = N-1; i >= 0; i--) {
		int top = pq.top();
		int temp = t[i];
		pq.pop();
		pq.push(top + temp);
	}
	int ans = 0;
	while (!pq.empty()) {
		ans = (ans < pq.top()) ? pq.top() : ans;
		pq.pop();
	}
	cout << ans << "\n";
	return 0;
}
