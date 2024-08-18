#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int N, M;
int map[9][9];
int c[9][9] = { false };
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int minVirus = 100000;

queue<pair<int, int>> virus;
vector<pair<int, int>> list;

int Bfs() {
	queue<pair<int, int>> q = virus;
	int count = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		c[x][y] = true;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > N || ny < 1 || ny > M || map[nx][ny] != 0) continue;
			if (!c[nx][ny]) {
				c[nx][ny] = true;
				q.push(make_pair(nx, ny));
				count++;
			}
		}
	}
	return count;
}
int WorkVirus(pair<int, int> w1, pair<int, int> w2, pair<int, int> w3) {
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++) c[i][j] = false;

	map[w1.first][w1.second] = 1;
	map[w2.first][w2.second] = 1;
	map[w3.first][w3.second] = 1;

	minVirus = min(minVirus, Bfs());

	map[w1.first][w1.second] = 0;
	map[w2.first][w2.second] = 0;
	map[w3.first][w3.second] = 0;

	return minVirus;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	int safeArea = 0;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				list.push_back(make_pair(i, j));
				safeArea++;
			}
			else if (map[i][j] == 2) {
				virus.push(make_pair(i, j));
			}
		}

	int dangerArea=999999999;
	// 3중 포문으로 x,y 커버
	for (int i = 0; i < list.size() - 2; i++)
		for (int j = i + 1; j < list.size() - 1; j++)
			for (int k = j + 1; k < list.size(); k++) {
				dangerArea = WorkVirus(list[i], list[j], list[k]);
			}

	cout << safeArea - dangerArea - 3;
}
