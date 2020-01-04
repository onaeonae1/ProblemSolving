#include<stdio.h>
#include <queue>
#define L 32001
using namespace std;

int indegree[L];
vector<int> vertex[L];

int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		indegree[b]++; //진입 차수. b에 하나 추가로 들어온다.
		vertex[a].push_back(b); //a는 b를 가리키고 있다.
	}
	queue<int> now;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0) now.push(i);

	while (!now.empty()) {
		int i = now.front(); now.pop();
		printf("%d ", i);

		for (int j = 0; j < vertex[i].size(); j++)
			if (--indegree[vertex[i][j]] == 0)
				now.push(vertex[i][j]);
	}
	return 0;
}
