#include<iostream>
#include<vector>
using namespace std;
int n, m, k;
int E[100005][3]; //엣지
int F[100005]; // 밀가루

int get_min(int a, int b) {
	int retValue = (a < b) ? a : b;
	return retValue;
}

int main() {

	// 밀가루에서 제일 가까운 곳으로ㄱㄱ
	int init = 9999999999;
	int ans = init;


	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		// 노드 번호 2개 + 길이를 입력
		cin >> E[i][0] >> E[i][1] >> E[i][2];
	}

	for (int i = 0; i < k; i++) {
		int temp;
		cin >> temp;
		F[temp] = 1;
	}

	for (int i = 0; i < m; i++) {
		int node1 = E[i][0];
		int node2 = E[i][1];
		int length = E[i][2];
		if (F[node1] + F[node2] == 1) {
			ans = get_min(ans, length);
		}
	}
	
	if (ans == init) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}

	return 0;
}
