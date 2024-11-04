#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	priority_queue<int, vector<int>, greater<int>> pq;
	int N;
	cin >> N;
	while (N--) {
		int t;
		cin >> t;
		pq.push(t);
	}
	while (!pq.empty()) {
		int t = pq.top();
		pq.pop();
		cout << t << " ";
	}
	return 0;
}
