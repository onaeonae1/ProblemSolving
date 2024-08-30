#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main() {
	int N, K;
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> N >> K;
	priority_queue<int, vector<int>, less<int>> pq; //큰 게 먼저 나오는 PQ
	while (N--) {
		int temp;
		cin >> temp;
		if (pq.empty()) {
			pq.push(temp);
		}
		else {
			int t = pq.size();
			if (t == K) {
				// 꽉찼다 방 빼라
				int top = pq.top();
				pq.pop();
				if (top > temp) {
					pq.push(temp);
				}
				else {
					pq.push(top);
				}
			}
			else {
				pq.push(temp);
			}
		}
	}
	cout << pq.top() << "\n";
	return 0;
}
