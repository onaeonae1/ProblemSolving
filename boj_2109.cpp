#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	// 작은 것 부터 제거하는 pq
	priority_queue<int, vector<int>, less<int>> pq;
	vector<vector<int>> items(10005);
	int maxDay = 0;
	for (int i = 0; i < N; i++) {
		int price, day;
		cin >> price >> day;
		items[day].push_back(price);
		maxDay = (maxDay < day) ? day : maxDay;
	}
	int ans = 0;
	for (int today = maxDay; today >= 1; today--) {
    // 강연은 ~일 안에 수행하면 되니깐 날짜 거꾸로 부터 돌아간다
		for (int idx = 0; idx < items[today].size(); idx++) {
			pq.push(items[today][idx]);
		}
		if (!pq.empty()) {
			int tmp = pq.top();
			ans += tmp;
			pq.pop();
		}
	}
	cout << ans << endl;
	return 0;
}
