#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> adj[1005];
bool visit[1005];
int N, M;
void bfs(int t) {
	queue<int> connect;
	connect.push(t);
	visit[t] = true;

	while (!connect.empty()) {
		int now = connect.front();
		connect.pop();
		for (int peer : adj[now]) {
			if (!visit[peer]) {
				visit[peer] = true;
				connect.push(peer);
			}
		}
	}
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			bfs(i);
			ans++;
		}
	}
	cout << ans << "\n";
	return 0; 
}
