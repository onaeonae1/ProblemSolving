#include<iostream>
#include<algorithm>
using namespace std;

int A[100005];
long long int dp[2][100005];

long long int get_max(long long int a, long long int b) {
	long long int retValue = -1;
	retValue = (a < b) ? b : a;
	return retValue;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	sort(A, A + n);
	dp[0][0] = 0;
	dp[1][0] = A[0];

	for (int i = 1; i < n; i++) {

		if (A[i - 1] == A[i]) {
			dp[0][i] = dp[0][i-1];
			dp[1][i] = dp[1][i - 1] + A[i];
		}
		else if (A[i] == A[i - 1] + 1) {
			dp[0][i] = get_max(dp[0][i - 1], dp[1][i - 1]);
			dp[1][i] = dp[0][i - 1] + A[i];
		}
		else {
			dp[0][i] = get_max(dp[0][i - 1], dp[1][i - 1]);
			dp[1][i] = get_max(dp[0][i - 1], dp[1][i - 1]) + A[i];
		}
	}
	long long int ans = get_max(dp[0][n - 1], dp[1][n - 1]);
	cout << ans << endl;
	return 0;
}
