#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	int N, me;
	int ans = 0;
	priority_queue<int, vector<int>> pq;
	cin >> N;
	cin >> me;
	for (int i = 1; i < N; i++) {
		int a;
		cin >> a;
		pq.push(a);
	}
	while (!pq.empty()) {
		int top = pq.top();
		pq.pop();
		if (top < me) break;
		else {
			pq.push(top - 1);
			me++;
			ans++;
		}
	}
	cout << ans << endl;
    return 0;
}
