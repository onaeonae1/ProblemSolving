#include<iostream>
using namespace std;
int parents[105] = { 0, };
int find(int x) { //부모 찾기
	if (x == parents[x]) {
		return x;
	}
	else {
		int p = find(parents[x]);
		parents[x] = p;
		return p;
	}
}
void uni(int x, int y) { //합치기
	x = find(x);
	y = find(y);
	if (x != y) {
		parents[y] = x;
	}
}

int main() {
	int n; //컴퓨터의 수
	int m; //관계의 수
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		parents[i] = i; //자기 자신에 대해 초기화
	}
	for (int i = 0; i < m; i++) {
		int alpha, beta;
		cin >> alpha; //전자
		cin >> beta; //후자
		uni(alpha, beta);
	}
	int count = 0;
	for (int i = 2; i <= n; i++) {
		if (find(1) == find(i)) {
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
