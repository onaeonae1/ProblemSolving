#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int N, M; 
int DP[105][10005];
int tempA[105];
int tempB[105];
vector<pair<int, int>> items;
bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tempA[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &tempB[i]);
	}
	int costSum = 0;
	int exLarge = -1;
	for (int i = 0; i < N; i++) {
		int mem = tempA[i];
		int cost = tempB[i];
		// check outliers
		costSum += cost;
		items.push_back(make_pair(cost, mem));
	}
	int ret = 99999;

	// sort(items.begin(), items.end(), compare);
	DP[0][items.at(0).first] = items.at(0).second;
	for (int i = 1; i < N; i++) {
		int currentCost = items.at(i).first;
		int currentMem = items.at(i).second;
		for (int j = 0; j <= costSum; j++) {
			DP[i][j] = DP[i - 1][j];
			if (j - currentCost >= 0) {
				int next = DP[i - 1][j - currentCost] + currentMem;
				DP[i][j] = (next < DP[i][j]) ? DP[i][j] : next;
			}
		}
	}
	for (int i = 0; i <= costSum; i++) {
		if (DP[N-1][i] >= M) {
			ret = (ret < i) ? ret : i;
		}
	}

	printf("%d", ret);
	return 0;
}
