#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, T;
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		for (int i = 0; i < N; i++) {
			long long  temp;
			cin >> temp;
			pq.push(temp);
		}

		long long ret = 0;
		while (pq.size() > 1) {
			long long t1 = pq.top();
			pq.pop();
			long long t2 = pq.top();
			pq.pop();

			ret += (t1 + t2);
			pq.push(t1 + t2);
		}

		cout << ret << "\n";
	}
	return 0;
}
