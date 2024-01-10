#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int R, C;
int N;
struct point {
	int px;
	int py;
	int fuel;
}points[1005];
bool compare(const point& alpha, const point& beta) {
	return (alpha.px + alpha.py) < (beta.px + beta.py);
}
int getDistance(int cy, int cx, int ty, int tx) {
	int ret = abs(ty - cy) + abs(tx - cx);
	return ret;
}
int dpFunc(int initFuel) {
	vector<int>dp(N + 2, -1);
	dp.at(0) = initFuel;

	for (int i = 1; i <= N+1; i++) {
		int currentX = points[i].px;
		int currentY = points[i].py;
		int fuelValue = points[i].fuel;
		for (int j = 0; j < i; j++) {
			int nextY = points[j].py;
			int nextX = points[j].px;
			if (nextY > currentY || nextX > currentX) {
				continue;
			}
			int cond = dp.at(j) - getDistance(currentY, currentX, nextY, nextX);
			if (cond < 0) {
				continue;
			}
			int next = cond + fuelValue;
			dp.at(i) = (dp.at(i) < next) ? next : dp.at(i);
		}
	}
	bool isDone = (dp.at(N + 1)>=0);
	return isDone;
}
int main() {
	scanf("%d %d", &R, &C);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &points[i].px, &points[i].py, &points[i].fuel);
	}
	sort(points + 1, points + N + 1, compare);
	points[0].fuel = 0;
	points[0].px = 1;
	points[0].py = 1;

	points[N + 1].fuel = 0;
	points[N + 1].px = R;
	points[N + 1].py = C;

	// 이분탐색 ㄱㄱ
	int first = 0;
	int end = 9999;
	while (first+1 < end) {
		int mid = (first + end) / 2;
		bool isDone = dpFunc(mid);
		// 못찾음 -> 올려서 찾아야 함
		if (!isDone) {
			first = mid; 
		}
		else {
			end = mid;
		}
	}
	printf("%d", end);
	return 0;
}
