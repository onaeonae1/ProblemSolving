#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M, T; //키 큰 놈들, 내 키, 타격 가능 횟수
	priority_queue<int, vector<int>, less<int>> pq; // 큰 놈들부터 나와봐
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		pq.push(temp);
	}
	int cnt = T;
	while (T--) {
		int top = pq.top();
		if (M > top || top==1) {
			// 더 볼 필요가 없음
			break;
		}
		pq.pop();
		top /= 2;
		pq.push(top);
	}
	int top = pq.top();
	if (M>top) {
		cout << "YES" << "\n";
		cout << cnt - T -1<< "\n";
	}
	else {
		cout << "NO" << "\n";
		cout << top << "\n";
	}
	return 0;
}
