#include<iostream>
#include<vector>
#include<queue>
#define N 505
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		int prev_rank[N] = { 0, };
		bool edge[N][N] = { false, };
		int income[N] = { 0, };
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &prev_rank[i]);
		}
		for (int i = 1; i < n; i++) {
			int start = prev_rank[i];
			for (int j = i + 1; j <= n; j++) {
				int end = prev_rank[j];
				income[end]++;
				edge[start][end] = true;
			}
		}
		scanf("%d", &m);
		for (int i = 1; i <= m; i++) {
			int alpha, beta;
			scanf("%d %d", &alpha, &beta);
			if (edge[alpha][beta]) {
				income[beta]--;
				edge[alpha][beta] = false;
				edge[beta][alpha] = true;
				income[alpha]++;
			}
			else {
				income[alpha]--;
				edge[beta][alpha] = false;
				edge[alpha][beta] = true;
				income[beta]++;
			}
		}
		//tsort
		queue<int> q;
		vector<int> res;
		for (int i = 1; i <= n; i++) {
			if (income[i] == 0) {
				q.push(i);
			}
		}
		bool isComplete = true;
		while (!q.empty()) {
			if (q.size() > 1) {
				isComplete = false;
				break;
			}
			else {
				int now = q.front();
				q.pop();
				res.push_back(now);
				for (int i = 1; i <= n; i++) {
					if (edge[now][i]) {
						income[i]--;
						if (income[i] == 0) {
							q.push(i);
						}
					}
				}
			}
		}
		if (!isComplete) {
			printf("?");
		}
		else {
			if (res.size() == n) {
				for (int i = 0; i < n; i++) {
					printf("%d ", res.at(i));
				}
			}
			else {
				printf("IMPOSSIBLE");
			}
		}
		printf("\n");
	}
	return 0;
}
