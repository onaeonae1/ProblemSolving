#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#define N 1000001
using namespace std;
int A[N];
int DP[N];
int ans[N];
pair<int, int> tracking[N];
//first  : index
//second : value
int main() {
	int n;
	scanf("%d", &n);
	//입력받기
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	//기본 처리
	tracking[0] = make_pair(0, A[0]);
	DP[0] = A[0];
	int idx = 0;
	//DP 돌아가는 과정
	for (int i = 1; i < n; i++) {
		int now = DP[idx];
		int ref = A[i];
		if (now < ref) { //한칸 바로 추가
			DP[++idx] = ref;
			tracking[i] = make_pair(idx, ref);
		}
		else {
			int ii = lower_bound(DP, DP + idx, ref) - DP;
			DP[ii] = ref;
			tracking[i] = make_pair(ii, ref);
		}
	}
	//정답 추적
	printf("%d\n", idx + 1);
	int length = idx;
	for (int i = n - 1; i >= 0; i--) {
		int index = tracking[i].first;
		int value = tracking[i].second;
		if (length == index) {
			ans[length] = value;
			length--;
		}
	}
	for (int i = 0; i <= idx; i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}
