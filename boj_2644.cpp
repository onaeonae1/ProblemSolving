#include<iostream>
using namespace std;
int N, M, head, tail;
int board[105][105];
int visited[105];
int ans = -1;
int depth = 0;
void dfs(int now) {
	if (now == tail) {
		visited[now] = 1;
		ans = depth;
		return;
	}
	visited[now] = 1;
	depth++;
	for (int x = 1; x <= N; x++) {
		if (visited[x] == 0 && board[now][x] == 1) {
			dfs(x);
		}
	}
	depth--;
	return;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	cin >> head >> tail;
	cin >> M;
	while (M--) {
		int parent, child;
		cin >> parent >> child;
		board[parent][child] = 1;
		board[child][parent] = 1;
	}
	dfs(head);
	cout << ans << "\n";
}
