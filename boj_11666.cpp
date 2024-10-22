#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N, M;
vector<pair<int, int>> items;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> M; // 사람 수 & 닫히는 시간 기준-> PQ에서 
	for (int i = 0; i < N; i++) {
		int start, usage;
		cin >> start >> usage;
		items.push_back({ start, usage });
	}
	int ret = 0;
	sort(items.begin(), items.end()); 
	priority_queue<int, vector<int>, greater<int>> pq; 
	pq.push(items[0].first + items[0].second);
	for (int i = 1; i < N; i++) {
		int start = items[i].first; 
		int usage = items[i].second;
		int endtime = start + usage;
		bool req = false;
		while (!pq.empty()) {
			// pq 검사 (logN)
			if (start < pq.top()) {
				break;
			}
			if (pq.top() + M < start) {
				pq.pop();
				continue;
			}
			else {
				req = true;
				pq.pop();
				break;
			}
		}
		if (req) {
			ret++;
		}
		pq.push(endtime);
	}
	cout << ret << "\n";
	return 0;
}
