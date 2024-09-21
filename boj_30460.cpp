#include<iostream>
using namespace std;
int arr[200005];
int DP[200005];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N+2; i++) {
		int t = 0;
		int left = -1e9;
		int right = -1e9;
		for (int j = i; j >= 1 && j >= i - 2; j--) {
			t += (arr[j] * 2 );
		}
		if (i >= 3) {
			right = DP[i - 3] + t;
		}
		left = DP[i - 1] + arr[i];
		DP[i] = (left < right) ? right : left;
	}
	cout << DP[N+2] << "\n";
	return 0;
}
