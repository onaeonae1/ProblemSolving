#include<iostream>
#include<vector>
using namespace std;

vector<int> E[1000];
int V[1000];
int X[1000], Y[1000]; 

void dfs(int node) {
	int s = E[node].size();
	for (int i = 0; i < s; i++) {
		// 미방문
		if (V[E[node][i]] == 0) {
			//방문 확인
			V[E[node][i]] = 1;
			dfs(E[node][i]);
		}
	}
	return;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> X[i] >> Y[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 모든 edge를 다 넣음 -> 그래프 만들기
			if (X[i] == X[j] || Y[i] == Y[j]) {
				E[i].push_back(j);
				E[j].push_back(i);
			}
		}
	}
	int ans=0;
	for (int i = 0; i < n; i++) {
		if (V[i] == 0) {
			ans++;
			dfs(i);
		}
	}
	ans--;

	cout << ans << endl;
	return 0;
}
