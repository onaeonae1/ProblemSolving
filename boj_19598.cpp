#include<iostream>
#include<queue> 
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int, int>> items;
int N;
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int do_search() {
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++) {
		// pq -> 필요한 방의 수
		int nowStart = items[i].first;
		int nowEnd = items[i].second;
		if (pq.empty()) {
			pq.push(nowEnd);
		}
		else {
			int top = pq.top();
			if (nowStart >= top) {
				pq.pop();
				pq.push(nowEnd);
			}
			else {
				pq.push(nowEnd);
			}
		}
	}
	return pq.size();
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		items.push_back({ start, end });
	}
	sort(items.begin(), items.end(), compare);
	int ret = do_search();

	cout << ret << "\n";
	return 0;
}
