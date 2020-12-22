#include<iostream>
#define N 1050000
bool tree[N]; //방문 체크
using namespace std;
void search(int now){
	int ret = 0;
	int parent = now;
	while (parent) {
		if (tree[parent]) {
			ret = parent;
		}
		parent = parent / 2;
	}
	if (ret) {
		printf("%d\n", ret);
	}
	else { //부동산 체크
		printf("%d\n", ret);
		tree[now] = true;
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int now;
		scanf("%d", &now);
		search(now);
	}
	return 0;
}
