#include<iostream>
#include<vector>
#include<queue>
#define N 50005
using namespace std;
int income[N]; //i번 노드로의 진입차수
vector<int> v[N]; //V[i] : i번 노드로부터 시작되는 정점들
int n, m; //정점,  고려해야 할 조합의 수
void tSort() {
	int result[N];
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (income[i] == 0) {
			q.push(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			printf("0");
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (--income[y] == 0) {
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", result[i]);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	vector<int> temp;
	for (int i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			int tempv;
			scanf("%d", &tempv);
			temp.push_back(tempv);
		}
		for (int j = 0; j < temp.size()-1; j++) {
			int start = temp.at(j);
			int end = temp.at(j + 1);
			v[start].push_back(end);
			income[end]++;
		}
		temp.clear();
	}
	tSort();
	return 0;
}
