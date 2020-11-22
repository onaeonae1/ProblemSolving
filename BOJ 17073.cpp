#include<iostream>
#include<vector>
#include<queue>
#define L 500005
using namespace std;
vector<int> adj[L];
bool check[L];
int leafCount;
void bfs(queue<int>& q) { //트리 bfs로 순회하면서 leaf 찾기
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		bool leaf = true;
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now].at(i);
			if (!check[next]) { //방문한 적 없다
				check[next] = true;
				q.push(next);
				leaf = false;
			}
		}
		if (leaf) {
			leafCount++;
		}
	}
}
int main() {
	int n, w;
	double water; //실수 처리
	scanf("%d %d", &n, &w);
	water = w;
	for (int i = 0; i < n-1; i++) {
		int node1, node2;
		scanf("%d %d", &node1, &node2);
		adj[node1].push_back(node2);
		adj[node2].push_back(node1);
	}
	//탐색 준비
	queue<int> q;
	check[1] = true;
	q.push(1);
	bfs(q);
	printf("%.9f", water / leafCount);
	return 0;
}
