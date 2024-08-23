#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	vector<pair<int, int>> items(N);
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		items[i] = { a,b };
	}
	sort(items.begin(), items.end());
	//시작 시간 기준으로 정렬되어 있다. -> 끝 시간만 보면 된다!
	int startTime = items[0].first;
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(0);
	for (int i = 0; i < N; i++) {
		int start = items[i].first;
		int end = items[i].second;
		if (!pq.empty()) {
			// 큐에서 뽑는 것 -> 가장 빨리 끝나는 시간
			int now = pq.top();
			if (start < now) {
				// 야 이거 끝날 때까지 안되겠는데?
				// 일단 이 수업을 위해서 추가해둔다
				pq.push(end);
			}
			else {
				// 야 이거 충분히 가능하다 바로 가자
				pq.pop();
				pq.push(end);
			}		
		}
	}
	int ans = pq.size();
	cout << ans << endl;
}
