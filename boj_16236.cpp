#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int board[25][25];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int nowx, nowy; 
int nowsize = 2;  // 현재 크기
int eaten; // 드신 횟수
int moves; // 진짜 드신 회수
int N;
struct food {
	int y, x, dist;
};
struct pq_cmp {
	bool operator()(food a, food b) {
		if (a.dist == b.dist) {
			if (a.y == b.y) {
				return a.x > b.x;
			}
			else {
				return a.y > b.y;
			}
		}
		else {
			return a.dist > b.dist;
		}
	}
};
bool inrange(int ty, int tx, int ns) {
	bool isValid = false;
	if (ty >= 0 && ty < N && tx >= 0 && tx < N) {
		// 범위 내에 있는지
		if (board[ty][tx] <= ns) {
			// 통과 가능한지
			isValid = true;
		}
	}
	return isValid;
}
int getLength(int ty, int tx, int ny, int nx) {
	return (abs(ty - ny) + abs(tx - nx));
}
void bfs() {
	int visited[25][25] = { 0, };
	queue<pair<int, int>> q; // 상어의 위치
	q.push({ nowy, nowx }); // 들어가주고
	visited[nowy][nowx] = 1;
	priority_queue<food, vector<food>, pq_cmp> pq;
	
	int current = 0;
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		int ny = now.first;
		int nx = now.second;

		for (int i = 0; i < 4; i++) {
			int ty = ny + dy[i];
			int tx = nx + dx[i];
			bool goodtoGo = inrange(ty, tx, nowsize);
			if (goodtoGo) {
				if (visited[ty][tx] == 0) {
					q.push({ ty,tx }); // 일단 상어새끼 움직이는 곳엔 넣어둠
					visited[ty][tx] = (visited[ny][nx]+1); // 이동거리는 이렇게 계산한다
					if (board[ty][tx] != 0 && board[ty][tx] < nowsize) {
						int tl = visited[ty][tx] - visited[nowy][nowx];
						pq.push({ ty,tx,tl });
					}
				}
			}
		}
		current++;
	}
	if (pq.empty()) {
		// 더 볼 것도 없구나
		return;
	}

	// 먹을 거 있으니깐 먹고 이동하고 계산하자
	food next = pq.top();
	pq.pop();
	if (++eaten == nowsize) {
		eaten = 0;
		nowsize++;
	}

	nowy = next.y;
	nowx = next.x;
	moves += next.dist;

	board[nowy][nowx] = 0;

	bfs();
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				nowy = i;
				nowx = j;
				board[i][j] = 0;
			}
		}
	}
	bfs();
	cout << moves << "\n";
	return 0;
}
