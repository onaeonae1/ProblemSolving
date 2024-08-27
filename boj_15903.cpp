#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, M;
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> N >> M;
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0; i < N; i++) {
		long long  temp;
		cin >> temp;
		pq.push(temp);
	}
	for (int i = 0; i < M; i++) {
		long long t1 = pq.top();
		pq.pop();
		long long t2 = pq.top();
		pq.pop();
		long long v = t1 + t2;
		pq.push(v); 
		pq.push(v);
	}
	
	long long ret = 0;
	while (!pq.empty()) {
		ret += pq.top();
		pq.pop();
	}

	cout << ret << "\n";
	
	return 0;
	
}
