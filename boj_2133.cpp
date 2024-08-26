#include<iostream>
using namespace std;
long long DP[35];
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	DP[0] = 1; // 계산을 위해 쓰는 친구에요
	DP[2] = 3;
	int N;
	cin >> N;
	if (N % 2 == 1) {
		// 홀수는 아무리 몸 비틀어도 안됨
		cout << 0 << "\n";
		return 0;
	}

	for (int i = 4; i <= N; i+=2) {
		long long temp = 0;
		temp += 3 * DP[i - 2];
		for (int j = i-4; j >= 0; j-=2) {
			temp += 2 * DP[j];
		}
		DP[i] = temp;
	}
	cout << DP[N] << "\n";
	return 0;
}
