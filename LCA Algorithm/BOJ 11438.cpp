#include<iostream>
#include<vector>
using namespace std;
int depth[100005] = { 0, }; //depth[V] : 노드 V의 높이 저장
int parent[100005][18] = { 0, }; //parent[V][i] : 노드 V의 2^i번째 부모 저장
vector<int> nodes[100005]; //각 노드들의 정보 저장
int N, M, d;
void SWAP(int &a, int &b) { int c = a; a = b; b = c; }
void TreeSet(int now, int dep) {
	depth[now] = dep++;
	for (int i = 1; i <= d; i++) {
		parent[now][i] = parent[parent[now][i - 1]][i - 1];
	}
	for (int i = 0; i < nodes[now].size(); i++) {
		int next = nodes[now][i];
		if (!depth[next]) {
			parent[next][0] = now;
			TreeSet(next, dep);
		}
	}
}
int main() {
	int results[100005] = { 0, };
	int index = 0;
	scanf("%d", &N);
	for (d = 1; (1 << d) <= N; d++); //높이 조정
	d--;
	//노드들의 정보 입력받기
	for (int i = 1; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	TreeSet(1, 1 );
	scanf("%d", &M);
	//이제 LCA를 구해볼 노드 쌍 입력받고 처리하기
	while (M--) {
		int a, b; 		scanf("%d %d", &a, &b);
		if (depth[a] < depth[b]) {
			SWAP(a, b);
		}
		//높이 맞춰주기
		for (int i = d; i >= 0; i--) {
			if (depth[b] <= depth[parent[a][i]]) {
				a = parent[a][i];
			}
		}
		//높이가 맞춰진 상태에서 같다
		if (a == b) {
			results[index] = a;
			index++;
			continue;
		}
		//높이가 맞춰진 상태에서 다르다!
		for (int i = d; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				a = parent[a][i];
				b = parent[b][i];
			}
		}
		results[index] = parent[a][0];
		index++;
	}
	for (int i = 0; i < index; i++) {
		printf("%d\n", results[i]);
	}
	return 0;
}
