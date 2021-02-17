#include<iostream>
#define L 100005
using namespace std;
int parent[L];
int G;
int P;
int gi[L];
int cnt;
int find_parent(int alpha) {
	if (alpha == parent[alpha]) {
		return alpha;
	}
	else {
		return parent[alpha] = find_parent(parent[alpha]);
	}
}
void merge(int alpha, int beta) {
	alpha = find_parent(alpha);
	beta = find_parent(beta);
	parent[alpha] = beta;
}
int main() {
	scanf("%d", &G);
	scanf("%d", &P);
	for (int i = 1; i <= G; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < P; i++) {
		int gi;
		scanf("%d", &gi);
		int gate_parent = find_parent(gi);
		if (gate_parent != 0) { //앞의 set에 붙일 수 있음
			// 붙이고 갯수 추가
			merge(gate_parent, gate_parent - 1);
			cnt++;
		}
		else {
			break;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
