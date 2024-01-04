#include<iostream>
#include<cstring>
using namespace std;

// N-> 남아있는 일 수
// M -> 존재하는 책들의 수(통상 n)
int N, M;
int costs[205];
int values[205];
int DP[405];
int temp[405];
int main() {
	int ret = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &costs[i], &values[i]);
	}

	for (int i = 0; i < M; i++) {
		int currentCost = costs[i];
		int currentValue = values[i];
		for (int j = 0; j <= 200; j++) {
			if (j - currentCost >= 0) {
				int now = DP[j];
				int next = DP[j - currentCost] + currentValue;
				temp[j] = (now < next) ? next : now;
			}
		}
		for (int j = 0; j <= N; j++) {
			DP[j] = (DP[j] < temp[j]) ? temp[j] : DP[j];
			ret = (ret < DP[j]) ? DP[j] : ret;
		}
		memset(temp, 0, sizeof(temp));
	}
	printf("%d", ret);
	return 0;
}
