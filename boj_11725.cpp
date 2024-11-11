#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N;
int parent[100005];
vector<int> adj[100005];
void bfs() {
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int t = q.front();
		q.pop();

		for (int item : adj[t]) {
			if (parent[item] == 0 && item != 1) {
				parent[item] = t;
				q.push(item);
			}
		}
	}
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	// 어떤 점 T 에 대해
	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	parent[1] = 1;
	bfs();
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}
	return 0;
}
