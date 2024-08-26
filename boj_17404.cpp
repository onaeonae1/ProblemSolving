#include<iostream>
#include<cstring>
using namespace std;
int price[1005][5]; //board[i][j] ->i번 집을 j로 칠하는데 드는 "비용"
int DP[1005][5]; // DP[i][j] -> i번 집을 j로 칠하는데 드는 답
int N;
int get_min(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}
void do_chore() {
	for (int i = 1; i < N; i++) {
		int first = DP[i - 1][0];
		int second = DP[i - 1][1];
		int third = DP[i - 1][2];

		int temp;
		//1
		temp = get_min(second, third);
		DP[i][0] = price[i][0] + temp;

		//2
		temp = get_min(first, third);
		DP[i][1] = price[i][1] + temp;

		//3
		temp = get_min(first, second);
		DP[i][2] = price[i][2] + temp;
	}
}
int main() {
	int ans = 1e9;
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> price[i][0] >> price[i][1] >> price[i][2];
	}

	// 1번으로 오프닝 -> 2,3 엔딩
	fill(&DP[0][0], &DP[N][3], 1e9);
	DP[0][0] = price[0][0];
	do_chore();
	ans = get_min(ans, DP[N - 1][1]);
	ans = get_min(ans, DP[N - 1][2]);

	// 2번으로 오프닝 -> 1,3 엔딩
	fill(&DP[0][0], &DP[N][3], 1e9);
	DP[0][1] = price[0][1];
	do_chore();
	ans = get_min(ans, DP[N - 1][0]);
	ans = get_min(ans, DP[N - 1][2]);


	// 3번으로 오프닝 -> 1,2 엔딩
	fill(&DP[0][0], &DP[N][3], 1e9);
	DP[0][2] = price[0][2];
	do_chore();
	ans = get_min(ans, DP[N - 1][0]);
	ans = get_min(ans, DP[N - 1][1]);
	
	cout << ans << "\n";

	return 0;
}
