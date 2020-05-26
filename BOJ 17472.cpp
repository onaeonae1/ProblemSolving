#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef struct a1a { int y, x, num; } point;
typedef struct a2a { int a, b, cost; } con;

int n, m, ans;
int board[15][15];
int visit[15][15];
int is_n;
int x_l[4] = { 0,0,-1,1 };
int y_l[4] = { 1,-1,0,0 };
vector<con> lists;
queue<point> q;
int parent[15];

int find(int n) {
	if (parent[n] == n) return n;
	else {
		parent[n] = find(parent[n]);
		return parent[n];
	}
}

void unite(int a, int b) {
	parent[find(a)] = find(b);
	/*
	int p1 = find(a);
	int p2 = find(b);
	if (p1 != p2) {
		parent[p1] = p2;
	}
	*/
}

bool isok(int y, int x) {
	if (1 <= y && y <= n && 1 <= x && x <= m) return true;
	else return false;
}

void dfs(int y, int x, int num) {
	board[y][x] = num;
	visit[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + y_l[i];
		int nx = x + x_l[i];
		if (isok(ny, nx) && board[ny][nx] == 0) {
			q.push({ y,x,num });
			break;
		}
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + y_l[i];
		int nx = x + x_l[i];

		if (isok(ny, nx) && board[ny][nx] > 0 && visit[ny][nx] == 0) {
			dfs(ny, nx, num);
		}
	}
}

void get_isn() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] > 0 && visit[i][j] == 0) {
				is_n++;
				dfs(i, j, is_n);
			}
		}
	}
}
void make_con() {
	while (!q.empty()) {
		point temp = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = temp.y + y_l[i];
			int nx = temp.x + x_l[i];
			while (true) {
				if (!isok(ny, nx)) break; //범위
				if (board[ny][nx] != 0 && board[ny][nx] != temp.num) { //육지발견
					if (abs(temp.y - ny) >= 3 || abs(temp.x - nx) >= 3) {
						lists.push_back({ temp.num, board[ny][nx], (abs(temp.y - ny) | abs(temp.x - nx)) - 1 });
					}
					break;
				}
				if (board[ny][nx] == temp.num) {
					break;
				}
				ny += y_l[i];
				nx += x_l[i];
			}
		}
	}
}
bool checker() {
	bool status = true;
	int standard = find(1); //이것과 전부 같아야 통과
	for (int i = 2; i <= is_n; i++) {
		if (standard != find(i)) {
			status = false;
			break;
		}
	}
	return status;
}

void get_ans() {
	if (lists.size() == 0) {
		ans = -1; return;
	}
	for (int i = 1; i <= 10; i++) {
		parent[i] = i;
	}
	sort(lists.begin(), lists.end(), [&](con a, con b) {
		return a.cost < b.cost;
	});
	int connections = 0;
	for (auto t : lists) {
		if (find(t.a) != find(t.b)) {
			unite(t.a, t.b);
			connections++;
			ans += t.cost;
		}
		if (connections + 1 == is_n) {
			break;
		}
	}
	bool res = checker();
	if (res == false) {
		ans = -1;
	}
}
int main() {
	//입력
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	get_isn();
	make_con();
	get_ans();
	printf("%d\n", ans);
	return 0;
}
