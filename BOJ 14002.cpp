#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#define L 100001
using namespace std;
int A[L];
int dp[L];
pair<int,int> tracking[L];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	dp[0] = A[0];
	tracking[0] = make_pair(0, A[0]);
	int idx = 0;
	for (int i = 1; i < n; i++) {
		int now = dp[idx];
		int ref = A[i];
		if (now < ref) {
			dp[++idx] = ref;
			tracking[i] = make_pair(idx, ref);
		}
		else {
			int ii = lower_bound(dp, dp + idx, ref) - dp;
			dp[ii] = ref;
			tracking[i] = make_pair(ii, ref);
		}
	}
	int answer[L] = { 0, };
	printf("%d\n", idx+1);
	int len = idx;
	for (int i = n - 1; i >= 0;  i--) {
		int index = tracking[i].first;
		int value = tracking[i].second;
		if (len == index) {
			answer[len] = value;
			len--;
		}
	}
	for (int i = 0; i <= idx; i++) {
		printf("%d ", answer[i]);
	}
	return 0;
}
