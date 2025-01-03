#include<iostream>
#include<vector>
using namespace std;
int N, T;
vector<int> tree[55]; //tree[i]: i 번 노드의 자식 노드들
int nodes[55];
int pp[55];
int cnt = 0;
void popdfs(int now) {
	for (int i = 0; i < tree[now].size(); i++) {
		int target = tree[now][i]; // 내 자식임
		popdfs(target);
	}
	nodes[now] = 0;
	pp[now] = -1;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	// 리프 노드 -> 자손이 0 인 노드 -> len(tree[k]) == 0
	// 노드의 삭제 -> 노드, 노드의 모든 자식 노드가 트리에서 제거 됨 => 전파됨
	for (int i = 0; i < N; i++) {
		int parent;
		cin >> parent;
		nodes[i] = 1;
		pp[i] = parent;
		if (parent != -1) {
			tree[parent].push_back(i);
		}
	}
	cin >> T;
	popdfs(T);
	for (int i = 0; i < N; i++) {
		bool isValid = (nodes[i] != 0);
		if (isValid) {
			bool hasChild = false;
			for (int j = 0; j < tree[i].size(); j++) {
				int child = tree[i][j];
				if (pp[child] == i) {
					hasChild = true;
					break;
				}
			}
			if (!hasChild) {
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}
