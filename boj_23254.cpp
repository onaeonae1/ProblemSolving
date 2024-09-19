#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int A[200000];
int B[200000];
priority_queue<pair<int, int>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M; 
	cin >> N >> M;
	N *= 24;

	for (int i = 0; i < M; i++) { 
		cin >> A[i]; 
	}
	for (int i = 0; i < M; i++) { 
		cin >> B[i]; 
	}

	for (int i = 0; i < M; i++) {
		if (A[i] < 100) { 
			pq.push(make_pair(min(B[i], 100 - A[i]), i)); 
		}
	}

	while ((N--) && !pq.empty()) {
		int a = pq.top().second, b = pq.top().first;
		A[a] += b;
		pq.pop();
		if (A[a] < 100) {
			int t = min(B[a], 100 - A[a]);
			pq.push({ t, a });
		}
	}

	int ans = 0;
	for (int i = 0; i < M; i++) { 
		ans += A[i]; 
	}

	cout << ans;
}
