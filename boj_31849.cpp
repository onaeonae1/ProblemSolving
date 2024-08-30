#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N, M, R, C;
int map[1005][1005];
int check[1005][1005];
vector<pair<pair<int, int>, int>> house;
queue<pair<pair<int, int>, pair<int, int>>> q;
int dx[4] = { 1 , 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int ans = 1e9;

void bfs() {
	while (!q.empty()) {
		int combi_x = q.front().first.first;
		int combi_y = q.front().first.second;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 1 && xx <= N && yy >= 1 && yy <= N) {
				if (check[xx][yy] == 0) {
					if (map[xx][yy] != 0) {
						int distance = (abs(combi_x - xx) + abs(combi_y - yy)) * house[map[xx][yy] - 1].second;
						ans = min(ans, distance);
					}
					check[xx][yy] = 1;
					q.push({ {combi_x, combi_y}, {xx, yy} });
				}
			}
		}
	}
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> R >> C;
	int cnt = 1;
	for (int i = 1; i <= R; i++) {
		int x, y, cost;
		scanf("%d %d %d", &x, &y, &cost);
		house.push_back({ {x, y}, cost });
		map[x][y] = cnt++;
	}
	for (int i = 1; i <= C; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		q.push({ {x, y}, {x, y} });
		check[x][y] = 1;
	}
	bfs();
	cout << ans;
	return 0;
}
