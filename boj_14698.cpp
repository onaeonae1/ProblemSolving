#include<iostream>
#include<queue>
#include<vector>
using namespace std;
long long int mod = 1000000007;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
		long long int ans = 1;
		for (int i = 0; i < N; i++) {
			long long int t;
			cin >> t;
			pq.push(t);
		}
		while (pq.size() >= 2) {
			long long int t1 = pq.top();
			pq.pop();
			long long int t2 = pq.top();
			pq.pop();

			long long int tt = t1*t2;
			ans = ((ans % mod) * (tt % mod)) % mod;
			ans %= mod;
			pq.push(t1 * t2);
		}
		cout << ans << "\n";
	}

	return 0;
}
