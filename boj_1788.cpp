#include<iostream>
using namespace std;
long long mod = 1000000000;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	long long ans = 1;
	if (N >=0) {
		long long fibAlpha = 0; // n-2
		long long fibBeta = 1; // n-1
		if (N == 0) {
			ans = 0;
		}
		if (N == 1) {
			ans = 1;
		}
		for (int i = 2; i <= N; i++) {
			int now = (fibBeta + fibAlpha) % mod;
			fibAlpha = fibBeta;
			fibBeta = now;
			ans = now;
		}
	}
	else {
		int temp = N * -1;
		int fibAlpha = 0; //n init with f(0) = 0
		int fibBeta = 1; //n-1. init with f(-1) = 1
		if (temp == 1) {
			ans = 1;
		}
		for (int i = 2; i <= temp; i++) {
			int now = (fibAlpha - fibBeta) % mod;
			fibAlpha = fibBeta;
			fibBeta = now;
			ans = now;
		}
		
	}
	int temp = 0;
	if (ans > 0) {
		temp = 1;
	}
	else if (ans < 0) {
		temp = -1;
	}
	else {
		temp = 0;
	}
	cout << temp << "\n";
	ans = (ans < 0) ? ans * -1 : ans;
	cout << ans << "\n";
	return 0;
}
