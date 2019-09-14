#include<iostream>
#define MOD 10007
using namespace std;
int main() {
	long long int DP[1005] = { 0, };
	long long int result = 0;
	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 3;
	DP[3] = 5;
	int n;
	cin >> n; 
	if (n <= 3) {
		result = DP[n] % MOD;
	}
	else {
		for (int i = 4; i <= n; i++) {
			DP[i] += 2 * DP[i - 2];
			DP[i] += DP[i - 1];
			DP[i] %= MOD;
		}
		result = DP[n] % MOD;
	}
	cout << result << endl;
	return 0;
}
