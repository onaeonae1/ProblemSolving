#include<iostream>
#define N_LIMIT 100
#define SUM_LIMIT 20000
using namespace std;

int N, M, X;
int A[N_LIMIT];
bool dp[N_LIMIT][SUM_LIMIT];
void func(int aValue) {
	for (int i =M - 1; i >= 1; i--) {
		for (int j = X * M; j >= aValue; j--) {
			// 나 들어오기 전에 sum 구성 가능하면 그거 사용
			dp[i + 1][j] = dp[i + 1][j] || dp[i][j - aValue];
		}
	}
	// 입력으로 들어온 것은 한명이서 커버 가능
	dp[1][aValue] = true;
}
int main() {
	scanf("%d %d %d", &N, &M, &X);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d %d", &A[i], &temp);
	}
	for (int i = 0; i < N; i++) {
		func(A[i]);
	}
	int ans = 0;
	// 전체합은 X * M 으로 통일됨
	for (int i = 0; i <= X * M; i++) {
		// M 명 선택처리
		if (dp[M][i]) {
			int next = i * (X * M - i);
			ans = (ans < next) ? next : ans;
		}
	}
	printf("%d", ans);
}
