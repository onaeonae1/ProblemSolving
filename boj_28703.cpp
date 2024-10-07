#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N;
priority_queue<int, vector<int>, greater<int>> minq;
priority_queue<int, vector<int>, less<int>> maxq;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	int maxValue = 1;
	int gap = 1e9;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		minq.push(t);
		maxq.push(t);
		maxValue = (maxValue < t) ? t : maxValue;
	}
	while (minq.top() <= maxValue) { // 어차피 이거보다 커지면 의미 없음
		int minV = minq.top();
		int maxV = maxq.top();
		int tempGap = (maxV - minV);
		gap = (gap < tempGap) ? gap : tempGap; // 이 친구를 최소화하는게 목적임
		minq.pop(); // 강해졌다
		minq.push(minV * 2);
		maxq.push(minV * 2);
	}

	cout << gap << "\n";
	return 0;
}
