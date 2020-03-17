#include<iostream>
#include<vector>
using namespace std;
int board[1005];
int main() {
	int n, k;
	int count = 0;
	int ans = -1;
	scanf("%d %d", &n, &k);
	for (int i = 2; i<=n; i++) {
		if (board[i] == 0) {
			for (int j = i; j <= n; j += i) {
				if (board[j] == 0) { //지워지지않음
					count++;
					board[j] = 1;
				}
				if (count == k) {
					ans = j;
					break;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
