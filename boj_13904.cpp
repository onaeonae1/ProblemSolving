#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N;
vector<int> homeworks[200005];
int main() {
	scanf("%d", &N);
	int maxDeadline = 0;
	for (int i = 0; i < N; i++) {
		int deadline, reward; 
		scanf("%d %d", &deadline, &reward);
		homeworks[deadline].push_back(reward);
		maxDeadline = (maxDeadline < deadline) ? deadline : maxDeadline;
	}
	int cnt = 0;
	priority_queue<int, vector<int>, less<int>> pq;

	for (int day = maxDeadline; day >= 1; day--) {
		for (int i = 0; i < homeworks[day].size(); i++) {
			pq.push(homeworks[day].at(i));
		}
		if (!pq.empty()) {
			cnt += pq.top();
			pq.pop();
		
		}
	}
	printf("%d", cnt);
	return 0;
}
