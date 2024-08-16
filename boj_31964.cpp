#include<iostream>
using namespace std;
int A[3005];
int T[3005];
int get_min(int a, int b) {
	if (a > b) {
		return b;
	}
	else {
		return a;
	}
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &T[i]);
	}
	int rightEnd = A[N - 1];
	int E = 0;
	int ans = 2 * rightEnd;
	for (int i = N - 1; i >= 0; i--) {
		int G = rightEnd - A[i];
		int temp = T[i] - (rightEnd + E + G);
		temp = (temp < 0) ? 0 : temp;
		E += temp;
	}
	ans += E;
	printf("%d\n", ans);
	return 0;
}
