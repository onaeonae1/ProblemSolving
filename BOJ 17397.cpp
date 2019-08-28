//숭고한 2019 알고리즘 캠프 중급반 E
//다이나믹
//공식 풀이 배포본을 참조하였습니다.
#include<iostream>
#include<string.h>
#define L 1005
using namespace std;
int board[L][205][15]; int A[L];
int n, m;
int min(int a, int b) {
	if (a <= b) { return a; }
	else { return b; }
}
//박탈감 계산. 어제와 오늘의 지출 차액의 제곱
int negative(int prev, int now) {
	if (prev > now) {return (prev - now) * (prev - now); }
	else { return 0;}
}
//dp(n,c,m) : n번째 날에 C만큼 지출하고 M만큼 남았을 때, n일까지 박탈감의 최소 합
int dp(int N, int C, int M) {
	if (N == n) { return 0; }
	if (board[N][C][M] != -1) { return board[N][C][M]; }
	int minor = 999999999;
	for (int i = 0; i <= min(10, C); i++) {
		minor = min(minor, dp(N + 1, C - i, i) + negative(A[N] + M, A[N + 1] + i));
	}
	return board[N][C][M] = minor;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	memset(board, -1, sizeof(board));
	cin >> n >> m;
	for (int i = 1; i <= n; i++)  {cin >> A[i];}
	cout << dp(1, m, 0);
	return 0;
}
