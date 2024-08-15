#include<iostream>
using namespace std;
int DP[1005][1005];
int map[1005][1005];
int getmax(int a, int b) {
	if (a < b) {
		return b; 
	}
	else {
		return a;
	}
}
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &DP[i][j]);
		}
	}
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int A[3] = { 0, }; // 0 -> left /1 -> up / 2-> diag
			if (j >= 1) {
				A[0] = DP[i][j - 1];
			}
			if (i >= 1) {
				A[1] = DP[i - 1][j];
			}
			if (i >= 1 && j >= 1) {
				A[2] = DP[i - 1][j - 1];
			}
			int temp = 0;
			for (int t = 0; t < 3; t++) {
				temp = getmax(temp, A[t]);
			}
			DP[i][j] += temp;
			ret = getmax(ret, DP[i][j]);
		}
	}
	printf("%d", ret);
	return 0;
}
