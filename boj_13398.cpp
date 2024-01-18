#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int N;
int numbers[100005];
int DP[100005][2];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &numbers[i]);
	}

	int ans = numbers[0];
	DP[0][0] = numbers[0];
	DP[0][1] = numbers[0];
	for (int i = 1; i < N; i++) {
		DP[i][0] = numbers[i];
		DP[i][1] = numbers[i];
		// delete X
		int head_a = DP[i - 1][0] + numbers[i];
		int head_b = numbers[i];
    
    // delete O
		int tail_a = DP[i - 1][0];
		int tail_b = DP[i - 1][1] + numbers[i];
		
		DP[i][0] = (head_a < head_b) ? head_b : head_a;
		DP[i][1] = (tail_a < tail_b) ? tail_b : tail_a;

		ans = (ans < DP[i][0]) ? DP[i][0] : ans;
		ans = (ans < DP[i][1]) ? DP[i][1] : ans;
	}
	printf("%d", ans);
	return 0;
}
