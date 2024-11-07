#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int L, S;
int board[105];
int teleport[105];
int ans = 105;
bool checkInRange(int pos) {
	return (0 < pos && pos <= 100);
}
bool checkValid(int pos, int cnt) {
	if (!checkInRange(pos)) {
		return false;
	}
	if (pos == 1) {
		return false;
	}
	bool visited = (board[pos] != 0); 
	if (visited) {
		bool isEfficient = (cnt < board[pos]);
		return isEfficient;
	}
	else {
		return true;
	}
}
void bfs() {
	queue<pair<int, int>> jobs;
	jobs.push({ 1,0 });
	board[1] = 0; 
	while (!jobs.empty()) {
		pair<int, int> now = jobs.front();
		jobs.pop();
		int pos = now.first;
		int cnt = now.second;
		if(pos==100){
			ans = (ans < cnt) ? ans : cnt;
		} 
		// 주사위를 굴린다
		for (int i = 1; i <= 6; i++) {
			int np = (pos + i);
			if (checkInRange(np)) {
				// 텔레포트
				np = (teleport[np] != 0) ? teleport[np] : np;
				if (checkValid(np, cnt+1)) {
					jobs.push({ np, cnt + 1 });
					board[np] = cnt + 1;
				}
			}
		}
	}
	return;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> L >> S;
	for (int i = 0; i < L + S; i++) {
		int start, end;
		cin >> start >> end;
		teleport[start] = end;
	}
	bfs();
	cout << ans << "\n";
	return 0;
}
