#include<iostream>
#include<vector>
#include<cmath>
#define K 100005
typedef long long ll;
using namespace std;
int n, m, k;
ll init(vector<ll> &num, vector<ll> &tree, int node, int st, int ed) { //트리 초기화
	if (st == ed) { //리프 노드 -> 값 그대로 저장
		return tree[node] = num[st];
	}
	else {
		//양쪽으로 확장하면서 리프노드의 값들 갱신. 합들을 저장
		return tree[node] = init(num, tree, node * 2, st, (st + ed) / 2) + init(num, tree, node * 2 + 1, (st + ed) / 2 + 1, ed);
	}
}
ll sum(vector<ll>& tree, int node, int st, int ed, int left, int right) { //특정 구간의 합
	//구간 합 리턴
	if (left > ed || right < st) { //범위 초과
		return 0;
	}
	if (left <= st && ed <= right) {
		return tree[node]; //값 리턴 후 탐색 종료
	}
	return sum(tree, node * 2, st, (st + ed) / 2, left, right) + sum(tree, node * 2 + 1, (st + ed) / 2 + 1, ed, left, right);
}
void update(vector<ll> &tree, int node, int st, int ed, int pos, ll diff) {
	//특정 부분의 값 변경을 트리에 반영
	if (pos<st || pos>ed) { //범위 초과
		return;
	}
	tree[node] = tree[node] + diff;
	if (st != ed) { //자식 노드들에도 값 변경
		//왼쪽 노드들
		update(tree, node * 2, st, (st + ed) / 2, pos, diff);
		//오른쪽 노드들
		update(tree, node * 2 + 1, (st + ed) / 2 + 1, ed, pos, diff);
	}
}
int main() {
	scanf("%d %d", &n, &m); //배열 크기, 쿼리
	int height = (int)ceil(log2(n)); //binary tree-> log2가 트리 높이
	int tree_size = 1 << (height + 1);
	vector<ll> tree(tree_size);
	vector<ll> num(n);
	for(int i = 0; i < n; i++) {
		scanf("%lld", &num[i]);
	}
	init(num, tree, 1, 0, n - 1); //초기화
	while (m--) {
		ll from, to;
		ll index, value;
		scanf("%lld %lld %lld %lld", &from, &to, &index, &value);

		// x 와 y 순서가 뒤바뀐 경우 처리
		ll start = from < to ? from : to;
		ll end = from < to ? to : from;

		//합 먼저 구하고
		printf("%lld\n", sum(tree, 1, 0, n - 1, start-1, end-1));
		
		//업데이트
		ll diff = value - num[--index];
		num[index] = value;
		update(tree, 1, 0, n - 1, index, diff);
	}
	return 0;;

}
