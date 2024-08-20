#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
vector<pair<int, int>> items;
vector<int> bags;
int main() {
	int N, M;
	cin >> N >> M;
	int a, b, temp;
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		items.push_back({ a,b });
	}
	for (int i = 0; i < M; i++) {
		cin >> temp;
		bags.push_back(temp);
	}
	
	sort(items.begin(), items.end());
	sort(bags.begin(), bags.end());

	priority_queue<int, vector<int>, less<int>> pq;
	int pos = 0;
	for (int i = 0; i < M; i++) {
		while ((pos < N) && (bags[i] >= items[pos].first)) {
			// 인덱스 조건 및 무게 조건을 만족하는 한 PQ에 전부 때려박는다
			pq.push(items[pos].second);
			pos++;
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans << endl;
	return 0;
}
