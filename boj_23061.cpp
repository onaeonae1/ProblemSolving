#include<iostream>
#include<cstring>
using namespace std;


// N -> 물건의 수, M-> 가방의 수
int N, M;
int weights[105];
int values[105];
int limits[105];

// dp 용 배열
int dp[105][1000005];

pair<long long, long long > headPair;
pair<long long, long long > tailPair;

// max weight 까지 하면 될거같은데..?
int main() {
	int maxWeight = 0;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &weights[i], &values[i]);
	}

	for (int i = 1; i <= M; i++) {
		scanf("%d", &limits[i]);
		maxWeight = (limits[i] < maxWeight) ? maxWeight : limits[i];
	}

	for (int i = 1; i <= N; i++) {
		int currentWeight = weights[i];
		int currentValue = values[i];
		for (int j = 0; j <= maxWeight; j++) {
			if (j - currentWeight >= 0) {
				int now = dp[i - 1][j];
				int next = dp[i - 1][j - currentWeight] + currentValue;
				dp[i][j] = (now < next) ? next : now;
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}	
		}
	}
	int retIndex = 1;
	for (int i = 2; i <= M; i++) {
		int currentLimit = limits[retIndex];//b
		int currentSum = dp[N][currentLimit]; //a
		int nextLimit = limits[i]; //d
		int nextSum = dp[N][nextLimit]; //c
		headPair = { limits[retIndex], dp[N][currentLimit]};
		tailPair = { limits[i], dp[N][nextLimit]};
		if (headPair.second * tailPair.first < tailPair.second * headPair.first) {
			retIndex = i;
		}
	}
	printf("%d", retIndex);
	return 0;
}
