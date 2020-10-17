#include<iostream>
#include<queue>
#include<vector>
#define L 32005
using namespace std;
int indegree[L]; 
vector<int> edge[L]; 
int main() {
	int n, m, start, end;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &start, &end);
		indegree[end]++; //end node로의 진입차수
		edge[start].push_back(end); //start->end 간선 추가
	}
	queue<int> now; //위상 정렬에 사용할 큐
	for (int i = 1; i <= n; i++) { //노드들 중에서
		if (indegree[i] == 0) {
			now.push(i);
		}
	}
	while (!now.empty()) { 
		int t = now.front();
		now.pop();
		printf("%d ", t); //해당 노드 방문
		for (int j = 0; j < edge[t].size(); j++) {
			if (--indegree[edge[t][j]] == 0) { //간선제거후 0이면
				now.push(edge[t][j]);
			}
		}
	}
	return 0;
}
