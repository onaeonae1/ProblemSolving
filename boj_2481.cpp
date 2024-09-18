#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<queue>
using namespace std;
map<long long, int> bitmap;
vector<int> adj[100005];
int dist[100005];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, L, Q; 
	cin >> N >> L;
	// 입력받기
	for (int i = 1; i <= N; i++) {
		string t;
		cin >> t;
		long long mul = 1;
		long long ret = 0;
		for (int j = t.size() - 1; j >= 0; j--) {
			ret += (t.at(j) - '0') * mul;
			mul *= 2;
		}
		bitmap[ret] = i;
	}
	// make graph
	for (pair<long long, int> item : bitmap) {
		long long bit = item.first;
		int idx = item.second;
		for (int i = 0; i < L; i++) {
			long long target = bit ^ (1 << i);
			if (bitmap.count(target)) {
				adj[idx].push_back(bitmap[target]);
			}
		}
	}

	// do bfs
	queue<int> visitQueue;
	visitQueue.push(1);
	dist[1] = -1;
	while (!visitQueue.empty()) {
		int nowIdx = visitQueue.front();
		visitQueue.pop();
		for (int item : adj[nowIdx]) {
			if (dist[item]==0) {
				visitQueue.push(item);
				dist[item] = nowIdx;
			}
		}
	}


	cin >> Q;
	while (Q--) {
		int target;
		cin >> target;
		if (!dist[target]) {
			cout << -1 << "\n";
		}
		else {
			vector<int> ret;
			while (target != -1) {
				ret.push_back(target);
				target = dist[target];
			}
			for (int i = ret.size()-1; i >=0; i--) {
				cout << ret.at(i) << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
