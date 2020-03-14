#include<iostream>
#define N 100
#define L 10001
using namespace std;
int DP[N][L]; //DP[i][j] : i번째 앱까지의 조회에 대해, 비용 j일때 최대 메모리
int cost[N];
int memory[N];
int n, m;
int ans = 987654321;
int max(int a, int b) {
	if (a <= b) {
		return b;
	}
	else {
		return a;
	}
}
int min(int a, int b) {
	if (a >= b) {
		return b;
	}
	else {
		return a;
	}
}
int main() {
	//입력
	scanf("%d %d ", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &memory[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &cost[i]);
	}
	//DP
	DP[0][cost[0]] = memory[0];
	for (int i = 1; i < n; i++) { //조회중인 앱
		for (int j = 0; j <= 10000; j++) { //비용 100 * 100 
			if (j - cost[i] >= 0) { //i번째 앱을 처리 가능한 비용임
				DP[i][j] = max(DP[i][j], DP[i - 1][j - cost[i]] + memory[i]);
			}
			DP[i][j] = max(DP[i][j], DP[i - 1][j]);
			if (DP[i][j] >= m) { //요구하는 메모리 채움
				ans = min(ans, j);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
