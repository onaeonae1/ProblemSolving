#include<iostream>
using namespace std;

int M[10005];
int A[10005];

int MAX_DEFAULT = -99999999;

int ans = MAX_DEFAULT;
int get_max(int a, int b) {
	int retValue;
	retValue = (a > b) ? a : b;
	return retValue;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		ans = MAX_DEFAULT;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
			ans = get_max(ans, A[i]);
		}

		M[0] = A[0];
		for (int i = 1; i < n; i++) {
			M[i] = get_max(M[i - 1] + A[i], A[i]);
			ans = get_max(ans, M[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
