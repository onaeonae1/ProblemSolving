#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
int N, K, L;
deque<pair<int, int>> rotates;
deque <pair<int, int>> snakePos;
int map[105][105];
int dx[5] = { 1, 0, -1, 0 };
int dy[5] = {0, 1, 0, -1 };


int rotate(int cd, int rot) {
	int temp = cd;
	temp += rot;
	if (temp < 0) {
		temp = 3;
	}
	temp = temp % 4;
	return temp;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &N);
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int ypos, xpos;
		scanf("%d %d", &ypos, &xpos);
		map[ypos][xpos] = 1;
	}
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		int time;
		char rotchar;
		int rotvalue;
		scanf("%d %c", &time, &rotchar);
		rotvalue = (rotchar == 'D') ? 1 : -1;
		rotates.push_back(make_pair(time, rotvalue));
	}
	sort(rotates.begin(), rotates.end());

	int direc = 0;
	int time = 0;
	int cx = 1;
	int cy = 1;
	snakePos.push_back(make_pair(1, 1));
	bool flag = true;
	while (true && flag) {
		int nx = cx + dx[direc];
		int ny = cy + dy[direc];

		// cout << "["<<time<<"] : {y: " << ny << " x : " << nx << "}" << endl;

		// 벽 충돌
		if (nx == 0 || nx > N || ny == 0 || ny > N) {
			time += 1;
			break;
		}
		// 신체 충돌
		for (pair<int, int> now: snakePos) {
			int now_y = now.first;
			int now_x = now.second;
			if (now_y == ny && now_x == nx) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			// cout << "BOOM!";
			time += 1;
			break;
		}

		// 사과를 고려
		if (map[ny][nx] == 1) {
			map[ny][nx] = 0;
			cy = ny;
			cx = nx;
			snakePos.push_back(make_pair(ny, nx));
		}
		else {
			cy = ny;
			cx = nx;
			snakePos.pop_front();
			snakePos.push_back(make_pair(ny, nx));
		}
		time++;

		if (!rotates.empty()) {
			pair<int, int> rot = rotates.front();
			if (rot.first == time) {
				direc = rotate(direc, rot.second);
				rotates.pop_front();
				// cout << "CHANGE -> [" << time << "] : {dy: " << dy[direc] << " dx : " << dx[direc] << "}" << endl;
			}
		}
	}
	cout << time;
	return 0;
}
