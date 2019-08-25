#include<iostream>
#include<algorithm>
#define LIM 300005
using namespace std;
int A[LIM] = { 0, };
int pref[LIM] = { 0, };
int main() {
	int n, q;
	cin >> n >> q;
	//입력받기
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}
	//정렬
	sort(A+1, A + n+1); 
	//부분합 구해주기
	for (int i = 1; i <= n; i++) {
		pref[i] = A[i] + pref[i-1];
	}
	while (q--) {
		int head, tail;
		scanf("%d %d", &head, &tail);
		printf("%d\n", pref[tail] - pref[head - 1]);
	}
	return 0;
}
