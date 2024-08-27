#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct item {
	int idx;
	int start;
	int end;
};
bool compare(const item& a, const item& b) {
	if (a.start == b.start) {
		return a.end < b.end;
	}
	else {
		return a.start < b.start;
	}
}
int lastH = 0;
int N;
vector<item> items;
int do_search() {
	int ret = 0;
	// 작은 놈이 먼저 나오는 pq -> 이제부터 이건 강의실이야
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++) {
		int nowStart = items[i].start;
		int nowEnd = items[i].end;
		if (pq.empty()) {
			pq.push(nowEnd);
		}
		else {
			int top = pq.top();
			// 가장 빨리 끝나는 시간 top
			if (nowStart >= top) {
				// 이어서 시작 가능함
				pq.pop();
				pq.push(nowEnd);
			}
			else {
				pq.push(nowEnd);
			}
		}
	}
	ret = pq.size();
	return ret;
}
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int idx, start, end;
		cin >> idx >> start >> end;
		lastH = (lastH < end) ? end : start;
		items.push_back({ idx, start, end });
	}
	sort(items.begin(), items.end(), compare);
	int ret = do_search();
	cout << ret << "\n";
  return 0;
}
