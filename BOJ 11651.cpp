#include<iostream>
#include<algorithm>
#define N 100005
using namespace std;
struct point {
	int x;
	int y;
}points[N];
bool compare(const point &a, const point &b) {
	if (a.y == b.y) {
		return a.x < b.x;
	}
	else {
		return a.y < b.y;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &points[i].x, &points[i].y);
	}
	sort(points + 0, points + n + 0, compare);
	for (int i = 0; i < n; i++) {
		printf("%d %d \n", points[i].x, points[i].y);
	}
	return 0;
}
