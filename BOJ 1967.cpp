#include<iostream>
#include<vector>
#include<cstring>
#define N 10005
using namespace std;
bool check[N]; //방문체크
vector<pair<int, int>> node[N]; //노드, 길이 저장
int ret, ed; //길이 값과 끝점
void dfs(int now, int length) {
	if (check[now]) {
		return;
	}
	//방문표시
	check[now] = true;
	if (ret < length) {
		ret = length;
		ed = now;
	}
	for (int i = 0; i < node[now].size(); i++) {
		//child에 대해서도 돌려준다.
		dfs(node[now][i].first, length + node[now][i].second);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	int parent, child, length;
	for (int i = 0; i < n-1; i++) { //n-1개의 줄이 주어짐에 주의 
		scanf("%d %d %d", &parent, &child, &length);
		node[parent].push_back(make_pair(child, length));
		node[child].push_back(make_pair(parent, length));
	}
	//root로부터 가장 멀리 떨어진 노드 찾기
	dfs(1, 0);
	//ret check 초기화
	ret = 0;
	memset(check, false, sizeof(check));
	//아까 찾은 ed 노드로부터 가장 멀리 있는 노드 찾기->트리 지름
	dfs(ed, 0);
	printf("%d\n", ret);
	return 0;
}
