#include<iostream>
#define INF 1500001
using namespace std;
int ret[INF][3];
int main() {
	int n, L, K;
	int count = 0;
	scanf("%d %d %d", &n, &K, &L);
	for (int i = 0; i < n; i++) {
		int team[3];
		bool flag = true;
		for (int j = 0; j < 3; j++) {
			scanf("%d", &team[j]);
		}
		for (int j = 0; j < 3; j++) {
			if (team[j] < L) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			int sum = team[0] + team[1] + team[2];
			if (sum >= K) {
				ret[count][0] = team[0];
				ret[count][1] = team[1];
				ret[count][2] = team[2];
				count++;
			}
		}
	}
	printf("%d\n", count);
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", ret[i][j]);
		}
	}
	return 0;

}
