#include<iostream>
#include<vector>
#include<queue>
#define N 50005
using namespace std;
int income[N]; //i번 노드로의 진입차수
vector<int> v[N]; //V[i] : i번 노드로부터 시작되는 정점들
int n, m; //정점,  간선의 수
void tSort() {
	int result[N];
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (income[i] == 0) {
			q.push(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			printf("cycle");
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (--income[y] == 0) {
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d", result[i]);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int start, end;
		scanf("%d %d", &start, &end);
		v[start].push_back(end);
		income[end]++;
	}
	tSort();
	return 0;
}
