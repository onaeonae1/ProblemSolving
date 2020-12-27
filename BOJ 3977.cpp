#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<cstring>
#define N 100001
using namespace std;
vector<vector<int>> edge; //정방향 그래프
vector<vector<int>> inverse; //역방향 그래프
vector<int> dfs_stack;
vector<vector<int>>scc;
int c;
int n, m; //구역의 수(=정점), 움직임의 수(=간선)
int result; 
int sccNumber[N];
int indegree[N];
bool visited[N];

void dfs(int now) {
	visited[now] = true;
	for (int i = 0; i < edge[now].size(); i++) {
		int next = edge[now][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
	dfs_stack.push_back(now); //탐색 결과 스택
}
void scc_add(int now) {
	visited[now] = true;
	sccNumber[now] = result; //정점이 특정 SCC에 속함
	scc.at(result).push_back(now); //해당 SCC에는 이 정점이 들어감
	for (int i = 0; i < inverse[now].size(); i++) {
		int next = inverse[now][i];
		if (!visited[next]) {
			scc_add(next);
		}
	}
}
void init() { //초기화
	memset(visited, 0, sizeof(visited));
	memset(sccNumber, 0, sizeof(sccNumber));
	memset(indegree, 0, sizeof(indegree));
	edge.clear();
	inverse.clear();
	dfs_stack.clear();
	scc.clear();
	result = 0;
}
int main() { //kosaraju
	scanf("%d", &c);
	while (c--) {
		init();
		scanf("%d %d", &n, &m);
		edge.resize(n + 1);
		inverse.resize(n + 1);
		scc.resize(n + 1);
		for (int i = 0; i < m; i++) {
			int from, to;
			scanf("%d %d", &from, &to);
			edge[from].push_back(to); //정방향 간선 표시
			inverse[to].push_back(from);
		}
		for (int i = 0; i < n; i++) { //1~n-1번 정점까지 정방향 dfs
			if (!visited[i]) { //방문한 적 없으면
				dfs(i);
			}
		}
		memset(visited, 0, sizeof(visited));
		while (!dfs_stack.empty()) { //SCC 초기화
			int now = dfs_stack.back();
			dfs_stack.pop_back();
			if (!visited[now]) {
				scc_add(now);
				result++;
			}
		}
		//degree
		for (int i = 0; i < n; i++) { //모든 정점에 대해
			for (int j = 0; j < edge[i].size(); j++) {
				int next = edge[i][j];
				if (sccNumber[i] != sccNumber[next]) {
					indegree[sccNumber[next]]++; //해당 SCC에 진입차수 +1
				}
			}
		}
		bool block = false;
		int target = -1;
		for (int i = 0; i < result; i++) { //모든 SCC 집합에 대해
			if (indegree[i] == 0) {
				if (target == -1) {
					target = i;
				}
				else { //초기화된적 있음 -> 진입차수0인거 2개 이상
					block = true;
				}
			}
		}
		if (!block) { //진입차수가 0인 SCC 집합은 오직 하나만 존재해야 함
			sort(scc[target].begin(), scc[target].end());
			for (int i = 0; i < scc[target].size(); i++) {
				printf("%d\n", scc[target][i]);
			}
		}
		else { 
			printf("Confued\n");
		}
		printf("\n");
		getchar();
	}
	return 0;
}
