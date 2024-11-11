#include<iostream>
#include<queue>
using namespace std;
int visit[505];
int N,T;
vector<int> items[505];
void bfs(int stp) {
	queue<pair<int, int>> qq;
	qq.push({ stp, 0 });
	visit[stp] = true;
	while (!qq.empty()) {
		pair<int, int> tt = qq.front();
		int t = tt.first;
		int r = tt.second;
		qq.pop();

		for (int item : items[t]) {
			if (!visit[item] && r<2) {
				qq.push({ item, r + 1 });
				visit[item] = true;
			}
		}
	}
	return;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	cin >> T;
	int stp = 1;
	for (int i = 0; i < T; i++) {
		int a, b;
		cin >> a >> b;
		items[a].push_back(b);
		items[b].push_back(a);
	}
	bfs(stp);
	int ans = 0;
	for (int i = 0; i < N + 1; i++) {
		if (visit[i] && i!=1) {
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}
